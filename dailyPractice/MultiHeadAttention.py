import torch
import torch.nn
import torch.nn.functional as F

class ScaledDotProductAttention(nn.Module):
    def __init__(self, temperature, dropout=0.1):
        super().__init__()
        self.temperature = temperature
        self.dropout = nn.Dropout(dropout)

    def forward(self, q, k, v, mask=None):
        attn = torch.matmul(q, k.transpose(-2, -1)) / self.temperature
        if mask is not None:
            attn = attn.mask_filled(mask==0, 1e-6)
        attn = self.dropout(F.softmax(attn, dim=-1))
        output = torch.matmul(attn, v)
        return output, attn

class LayerNorm(nn.Module):
    def __init__(self, d_model, eps):
        super().__init__()
        self.d_model = d_model
        self.eps = eps
        self.gamma = nn.Parameter(torch.ones(d_model))
        self.beta = nn.Parameter(torch.zeros(d_model))

    def forward(self, x):
        mean = x.mean(dim=-1, keepdim=True)
        var = x.mean(dim=-1, unbiased=False, keepdim=True)
        x_norm = (x - mean) / torch.sqrt(var + self.eps)
        return self.gamma * x_norm + self.beta

class MultiHeadAttention(nn.Module):
    def __init__(self, d_model, d_k, d_v, n_head, dropout=0.1):
        super().__init__()
        self.d_model = d_model
        self.d_k = d_k
        self.d_v = d_v
        self.n_head = n_head

        self.w_q = nn.Linear(d_model, n_head * d_k, bias=False)
        self.w_k = nn.Linear(d_model, n_head * d_k, bias=False)
        self.w_v = nn.Linear(d_model, n_head * d_v, bias=False)
        self.fc = nn.Linear(n_head * d_v, d_model, bias=False)

        self.attention = ScaledDotProductAttention(temperature=d_k**0.5)
        self.dropout = nn.Dropout(dropout)
        self.layer_norm = LayerNorm(d_model=d_model)

    def forward(self, q, k, v, mask=None):
        batch_size, len_q, len_k, len_v = q.size(0), q.size(1), k.size(1), v.size(1)
        d_model, d_k, d_v, n_head = self.d_model, self.d_k, self.d_v, self.n_head

        residual = q

        q = self.w_q(q).view(batch_size, len_q, n_head, d_k)
        k = self.w_k(k).view(batch_size, len_k, n_head, d_k)
        v = self.w_v(v).view(batch_size, len_v, n_head, d_v)

        q, k, v = q.transpose(1, 2), k.transpose(1, 2), v.transpose(1, 2)

        if mask is not None:
            mask = mask.unsqueeze(1)

        output, attn = self.attention(q, k, v, mask=mask)
        output.transpose(1, 2).contiguous().view(batch_size, len_q, -1)
        output = self.dropout(self.fc(output))
        output += residual
        output = self.layer_norm(output)
        return output, attn