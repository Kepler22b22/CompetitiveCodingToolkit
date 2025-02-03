#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DisjointSet{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n){
        parent.resize(n, -1);
        rank.resize(n, 0);
    }

    int find(int i){
        if(parent[i] == -1) {return i;}
        return parent[i] = find(parent[i]);
    }

    void unionSet(int u, int v){
        int rootU = find(u);
        int rootV = find(v);
        if(rank[rootU] != rank[rootV]){
            if(rank[rootU] < rank[rootV]) {parent[rootU] = rootV;}
            else if(rank[rootU] > rank[rootV]) {parent[rootV] = rootU;}
            else{
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void KruskalAlgo(vector<tuple<int, int, int>> &edges, int n){
    sort(edges.begin(), edges.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b){
        return get<2>(a) < get<2>(b);
    });
    
    DisjointSet set(n);
    vector<tuple<int, int, int>> MST;
    for(const auto &edge : edges){
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);
        if(set.find(u) != set.find(v)){
            set.unionSet(u, v);
            MST.push_back(edge);
        }
        if(MST.size() == n - 1){break;}
    }

    // Print the MST
    cout << "Edge\tWeight\n";
    for (const auto& edge : MST) {
        cout << get<0>(edge) << " - " << get<1>(edge) << "\t" << get<2>(edge) << "\n";
    }
}

int main() {
    int n = 6; // Number of vertices

    // Correcting the graph as an undirected weighted graph
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 3, 3},
        {1, 2, 4}, {1, 3, 3},
        {2, 4, 1}, {2, 5, 3},
        {3, 5, 2}, {3, 4, 6},
        {4, 5, 5}
    };

    KruskalAlgo(edges, n);

    return 0;
}