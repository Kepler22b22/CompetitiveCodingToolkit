#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void primsAlgo(vector<vector<pair<int, int>>> &edges, int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> parent(n, -1), key(n, INT_MAX);
    unordered_set<int> inMST;
    key[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST.count(u)){continue;}
        inMST.insert(u);
        for(const auto &edge : edges[u]){
            if(!inMST.count(edge.first) && key[edge.first] > edge.second){
                key[edge.first] = edge.second;
                parent[edge.first] = u;
                pq.push({edge.second, edge.first});
            }
        }
    }
    cout << "Edge\tWeight" << endl;
    for(int i = 0; i < n; i++){
        cout << parent[i] << " " << i << " " << key[i] << endl;
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

    /*
    Expected Output:
    Edge    Weight
    0-1 2
    5-2 3
    0-3 3
    2-4 1
    3-5 2
    */

    return 0;
}