#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> edges;

public:
    Graph(int vertices){
        V = vertices;
        edges.resize(V);
    }

    void addEdges(int u, int v, int w){
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    void dfs(int start){
        cout << "DFS starts: " << endl;
        vector<int> visit(V, 0);
        dfs_helper(start, visit);
        cout << endl;
    }

    void dfs_helper(int u, vector<int> &visit){
        if(visit[u]){return;}
        cout << u << " ";
        visit[u] = 1;
        for(const auto &edge : edges[u]){
            dfs_helper(edge.first, visit);
        }
    }

    void bfs(int start){
        cout << "BFS starts" << endl;
        vector<int> visit(V, 0);
        queue<int> q;
        visit[start] = 1;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(const auto & edge : edges[u]){
                if(!visit[edge.first]){
                    visit[edge.first] = 1;
                    q.push(edge.first);
                }
            }
        }
        cout << endl;
    }

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << "Node " << i << ": ";
            for(const auto &edge : edges[i]){
                cout << "(" << edge.first << ", weight: " << edge.second << ")";
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