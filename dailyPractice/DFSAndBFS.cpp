#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj; // weighted graph

public:
    Graph(int vertices){
        V = vertices;
        adj.resize(V);
    }

    void addEdges(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    void dfs_helper(int u, vector<int> &visit){
        visit[u] = 1;
        cout << u << " ";
        for(const auto&nei : adj[u]){
            if(!visit[nei.first]){
                dfs_helper(nei.first, visit);
            }
        }
    }

    void dfs(int start){
        cout << "DFS starts: " << endl;
        vector<int> visit(V, 0);
        dfs_helper(0, visit);
        cout << endl;
    }

    void bfs(int start){
        cout << "BFS starts: " << endl;
        queue<int> q;
        vector<int> visit(V, 0);
        q.push(start);
        visit[start] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(const auto&nei : adj[u]){
                if(!visit[nei.first]){
                    visit[nei.first] = 1;
                    q.push(nei.first);
                }
            }
        }
        cout << endl;
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": ";
            for (auto &neighbor : adj[i]) {
                cout << "(" << neighbor.first << ", weight: " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};


int main() {
    Graph g(7); // Create a graph with 7 vertices (0 to 6)
    
    // Adding weighted edges
    g.addEdges(0, 1, 4);
    g.addEdges(0, 2, 2);
    g.addEdges(1, 3, 6);
    g.addEdges(1, 4, 3);
    g.addEdges(2, 5, 8);
    g.addEdges(2, 6, 5);

    g.printGraph(); // Debugging: Print the graph

    // Performing DFS and BFS
    g.dfs(0);
    g.bfs(0);

    return 0;
}