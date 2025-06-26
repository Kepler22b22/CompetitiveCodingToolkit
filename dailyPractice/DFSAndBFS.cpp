#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int verticies){
        V = verticies;
        adj.resize(V);
    }

    void addEdges(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dfsI(int start){
        cout << "Iterative DFS starts: " << endl;
        stack<int> stk;
        unordered_set<int> visit;
        stk.push(start);
        while(!stk.empty()){
            int u = stk.top();
            stk.pop();
            if(visit.count(u)){continue;}
            visit.insert(u);
            cout << u << " ";
            for(const auto &edge : adj[u]){
                if(!visit.count(edge.first)){
                    stk.push(edge.first);
                }
            }
        }
        cout << endl;
    }

    void dfsR(int start){
        cout << "Recusive DFS starts: " << endl;
        unordered_set<int> visit;
        dfs_helper(start, visit);
        cout << endl;
    }

    void dfs_helper(int u, unordered_set<int> &visit){
        if(visit.count(u)){return;}
        visit.insert(u);
        cout << u << " ";
        for(const auto &edge : adj[u]){
            dfs_helper(edge.first, visit);
        }
    }

    void bfs(int start){
        cout << "BFS starts: " << endl;
        queue<int> q;
        unordered_set<int> visit;
        q.push(start);
        visit.insert(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(const auto &edge : adj[u]){
                if(!visit.count(edge.first)){
                    visit.insert(edge.first);
                    q.push(edge.first);
                }
            }
        }
        cout << endl;
    }

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << "Node "  << i << ": ";
            for(const auto &edge : adj[i]){
                cout << "(" << edge.first << ", weight: " << edge.second << ") ";
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
    g.dfsI(0);
    g.dfsR(0);
    g.bfs(0);

    /*Expected Output: 
    Node 0: (1, weight: 4) (2, weight: 2)
    Node 1: (0, weight: 4) (3, weight: 6) (4, weight: 3)
    Node 2: (0, weight: 2) (5, weight: 8) (6, weight: 5)
    Node 3: (1, weight: 6)
    Node 4: (1, weight: 3)
    Node 5: (2, weight: 8)
    Node 6: (2, weight: 5) 
    Iterate DFS starts: 
    0 2 6 5 1 4 3 
    Recursive DFS starts: 
    0 1 3 4 2 5 6 
    BFS starts: 
    0 1 2 3 4 5 6 
    */

    return 0;
}