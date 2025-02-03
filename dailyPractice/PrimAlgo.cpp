#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void primsAlgo(vector<vector<pair<int, int>>> &edges, int n){
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    unordered_set<int> MST;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, vertex
    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();
        if(MST.count(v)){continue;}
        MST.insert(v);
        for(const auto & edge : edges[v]){
            if(edge.second < key[edge.first] && !MST.count(edge.first)){
                key[edge.first] = edge.second;
                parent[edge.first] = v;
                pq.push({edge.second, edge.first});
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<pair<int, int>>> graph(n);

    // Correcting the graph as an undirected weighted graph
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 3, 3},
        {1, 2, 4}, {1, 3, 3},
        {2, 4, 1}, {2, 5, 3},
        {3, 5, 2}, {3, 4, 6},
        {4, 5, 5}
    };

    // Add edges in both directions
    for (auto [u, v, w] : edges) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    primsAlgo(graph, n);

    return 0;
}