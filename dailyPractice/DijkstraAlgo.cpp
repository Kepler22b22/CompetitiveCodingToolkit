#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> DijkstraAlgo(vector<vector<pair<int, int>>> &edges, int n, int start){
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_set<int> visit;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visit.count(u)) continue;
        visit.insert(u);
        for(const auto &edge : edges[u]){
            if(!visit.count(edge.first) && dist[edge.first] > edge.second + dist[u]){
                dist[edge.first] = edge.second + dist[u];
                pq.push({dist[edge.first], edge.first});
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

    /*
    Expected Output:
    Shortest distances from node 0:
    Node 0 : 0
    Node 1 : 2
    Node 2 : 6
    Node 3 : 3
    Node 4 : 9
    Node 5 : INF
    Node 6 : INF
    */

    return 0;
}