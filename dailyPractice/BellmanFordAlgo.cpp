#include <iostream>
#include <vector>

using namespace std;

void BellmanFordAlgo(vector<tuple<int, int, int>> &edges, int n){
    int superNode = n;
    for(int i = 0; i < n; i++){
        edges.push_back({superNode, i, 0});
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[superNode] = 0;
    for(int i = 0; i <= n; i++){
        for(const auto &[u, v, w] : edges){
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
        for(int i = 0; i < n; i++){
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    for(const auto &[u, v, w] : edges){
        if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
            cout << "Negative cycle detected. " << endl;
            cout << dist[v] << " " << dist[u] + w << endl;
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX){cout << "Node " << i << ": INF" << endl;}
        else{cout << "Node " << i << ": " << dist[i] << endl;} 
    }
}

int main() {
    int n = 4; // number of original nodes
    vector<tuple<int, int, int>> edges = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 0, -1}
    };

    BellmanFordAlgo(edges, n);

    return 0;
}
