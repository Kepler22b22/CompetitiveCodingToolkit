#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices){
        V = vertices;
        adj.resize(V);
    }

    void addEdges(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dfs(int start){
        cout << "DFS starts: " << endl;
        vector<int> visit(V, 0);
        dfs_helper(start, visit);
        cout << endl;
    }

    void dfs_helper(int node, vector<int> &visit){
        if(visit[node]){return;}
        cout << node << " ";
        visit[node] = 1;
        for(const auto &nei : adj[node]){
            dfs_helper(nei.first, visit);
        }
    }

    void bfs(int start){
        cout << "BFS starts: " << endl;
        vector<int> visit(V, 0);
        queue<int> q;
        visit[start] = 1;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(const auto & nei : adj[node]){
                if(!visit[nei.first]){
                    visit[nei.first] = 1;
                    q.push(nei.first);
                }
            }
        }
        cout << endl;
    }

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << "Node " << i << ": ";
            for(const auto& nei : adj[i]){
                cout << "(" << nei.first << ", weight: " << nei.second << ")";
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

    /*Expected Output: 
    Node 0: (1, weight: 4) (2, weight: 2)
    Node 1: (0, weight: 4) (3, weight: 6) (4, weight: 3)
    Node 2: (0, weight: 2) (5, weight: 8) (6, weight: 5)
    Node 3: (1, weight: 6)
    Node 4: (1, weight: 3)
    Node 5: (2, weight: 8)
    Node 6: (2, weight: 5)

    DFS starts:
    0 1 3 4 2 5 6

    BFS starts:
    0 1 2 3 4 5 6
    */

    return 0;
}