#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Edge; //Pair to represent (weight, vertex)

void primsAlgo(vector<vector<Edge>> &graph, int n){
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; //min-heap to store (weight, vertex)

    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]){continue;}
        inMST[u] = true;
        for(auto &edge : graph[u]){
            int w = edge.first;
            int v = edge.second;
            if(!inMST[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    //Print MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<Edge>> graph(n);

    // Add edges (u, v, weight)
    graph[0].push_back({2, 1});
    graph[0].push_back({3, 3});
    graph[1].push_back({2, 0});
    graph[1].push_back({4, 2});
    graph[1].push_back({3, 3});
    graph[2].push_back({4, 1});
    graph[2].push_back({5, 3});
    graph[3].push_back({3, 0});
    graph[3].push_back({3, 1});
    graph[3].push_back({5, 2});
    graph[3].push_back({6, 4});
    graph[4].push_back({6, 3});

    primsAlgo(graph, n);

    return 0;
}