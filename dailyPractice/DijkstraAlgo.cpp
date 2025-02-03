#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> DijkstraAlgo(vector<vector<pair<int, int>>> &edges, int n, int start){
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int v = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        if(dis > dist[v]){continue;}
        for(const auto &[u, w] : edges[v]){
            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] + w;
                pq.push({w, u});
            }
        }
    }
    return dist;
}

int main() {
    int n = 7;
    vector<vector<pair<int, int>>> edges(n);

    // Add edges (u, v, weight)
    edges[0].push_back({1, 2});
    edges[0].push_back({3, 3});
    edges[1].push_back({0, 2});
    edges[1].push_back({2, 4});
    edges[1].push_back({3, 3});
    edges[2].push_back({1, 4});
    edges[2].push_back({3, 5});
    edges[3].push_back({0, 3});
    edges[3].push_back({1, 3});
    edges[3].push_back({2, 5});
    edges[3].push_back({4, 6});
    edges[4].push_back({3, 6});
    int start = 0;
    vector<int> distances = DijkstraAlgo(edges, n, start);

    // Print shortest distances
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : ";
        if (distances[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << distances[i] << "\n";
        }
    }

    return 0;
}