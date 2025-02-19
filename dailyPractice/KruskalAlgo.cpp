#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n){
        parent.resize(n, -1);
        rank.resize(n, 0);
    }

    int find(int i){
        if(parent[i] == -1){return i;}
        return parent[i] = find(parent[i]);
    }

    void unionSet(int u, int v){
        int rootu = find(u), rootv = find(v);
        if(rank[rootu] < rank[rootv]){parent[rootu] = rootv;}
        else if(rank[rootu] > rank[rootv]){parent[rootv] = rootu;}
        else{
            parent[rootv] = rootu;
            rank[rootu]++;
        }
    }
};

void KruskalAlgo(vector<tuple<int, int, int>> &edges, int n){
    sort(edges.begin(), edges.end(), [](const tuple<int, int, int>&a, const tuple<int, int, int>&b){
        return get<2>(a) < get<2>(b);
    });
    vector<tuple<int, int, int>> inMST;
    DisjointSet set(n);
    for(const auto &[u, v, w] : edges){
        if(set.find(u) != set.find(v)){
            set.unionSet(u, v);
            inMST.push_back({u, v, w});
        }
        if(inMST.size() + 1 == n){break;}
    }
    for(const auto & edge : inMST){
        cout << get<0>(edge) << " - " << get<1>(edge) << " " << get<2>(edge) << endl;
    }
}

int main() {
    int n = 6; // Number of vertices

    // Correcting the graph as an undirected weighted graph
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 3, 3},
        {1, 2, 4}, {1, 3, 3},
        {2, 4, 1}, {2, 5, 3},
        {3, 5, 2}, {3, 4, 6},
        {4, 5, 5}
    };

    KruskalAlgo(edges, n);

    /*
    Expected Output:
    2 - 4 1
    0 - 1 2
    3 - 5 2
    0 - 3 3
    2 - 5 3
    */

    return 0;
}