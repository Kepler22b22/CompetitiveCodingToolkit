#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Edge;

class DisjointSet{
private:
    vector<int> rank;

public:
    DisjointSet(int n){
        rank.resize(n, 0);
    }

    int find(int u){
        int x = u;
        while(rank[x] > 0){x = rank[x];}
        return x;
    }

    void unionSet(int u, int v){
        if(rank[u] < rank[v]){
            rank[u] += rank[v];
            rank[v] = u;
        }
        else{
            rank[v] += rank[u];
            rank[u] = v;
        }
    }
};

void kruskalsAlgo(vector<vector<int>> &graph, int n){
    int i = 0;
    while(i < n - 1){
        int min = INT_MAX;
        for(int j = 0; j < ){}
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<Edge>> graph(n);

    // Add edges (u, v, weight)
    graph[0].push_back({2, 1}); // Edge 0 - 1, weight 2
    graph[0].push_back({3, 3}); // Edge 0 - 3, weight 3
    graph[1].push_back({2, 0}); // Edge 1 - 0, weight 2
    graph[1].push_back({4, 2}); // Edge 1 - 2, weight 4
    graph[1].push_back({3, 3}); // Edge 1 - 3, weight 3
    graph[2].push_back({4, 1}); // Edge 2 - 1, weight 4
    graph[2].push_back({5, 3}); // Edge 2 - 3, weight 5
    graph[3].push_back({3, 0}); // Edge 3 - 0, weight 3
    graph[3].push_back({3, 1}); // Edge 3 - 1, weight 3
    graph[3].push_back({5, 2}); // Edge 3 - 2, weight 5
    graph[3].push_back({6, 4}); // Edge 3 - 4, weight 6
    graph[4].push_back({6, 3}); // Edge 4 - 3, weight 6

    kruskalsAlgo(graph, n);

    return 0;
}