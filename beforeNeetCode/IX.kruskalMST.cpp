#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Edge;

struct FullEdge{
    int u, v, weight;
};

/*bool compareEdges(const FullEdge &a, const FullEdge &b){
    return a.weight < b.weight;
}*/

class DisjointSet{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n, -1);
    }

    int find(int i){
        if(parent[i] == -1){return i;}
        return parent[i] = find(parent[i]);
    }

    void unionSet(int u, int v){
        int rootX = find(u);
        int rootY = find(v);
        if(rootX != rootY ){
            if(rank[rootX] < rank[rootY]){parent[rootX] = rootY;}
            else if(rank[rootX] > rank[rootY]){parent[rootY] = rootX;}
            else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalsAlgo(vector<vector<Edge>> &graph, int n){
    vector<FullEdge> edges;

    // Convert adjacency list to a list of edges
    for(int u = 0; u < n; u++){
        for(const auto & edge : graph[u]){
            int w = edge.first;
            int v = edge.second;
            if(u < v){edges.push_back({u, v, w});} // Avoid duplicate edges in an undirected graph
        }
    }

    // Sort edges by weight
    //sort(edges.begin(), edges.end(), compareEdges);
    sort(edges.begin(), edges.end(), [](const FullEdge &a, const FullEdge &b) {
        return a.weight < b.weight;
    });
    
    DisjointSet set(n);
    vector<FullEdge> MST;
    int mstW = 0;

    for(const auto &edge : edges){
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;
        if(set.find(u) != set.find(v)){
            set.unionSet(u, v);
            MST.push_back(edge);
            mstW += w;
        }
        if(MST.size() == n - 1){break;}
    }

    // Print the MST
    cout << "Edge\tWeight\n";
    for (const auto& edge : MST) {
        cout << edge.u << " - " << edge.v << "\t" << edge.weight << "\n";
    }
    cout << "Total Weight of MST: " << mstW << "\n";
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