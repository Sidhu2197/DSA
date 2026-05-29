#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int v;
    vector<list<int>> adj;   // adjacency list

public:
    Graph(int v) : v(v), adj(v) {}

    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);   // undirected graph
    }

    bool dfs(int src, int dest, vector<bool>& vis) {// TC : 0(V+E)
        if (src == dest) return true;
        vis[src] = true;

        for (int neigh : adj[src]) {
            if (!vis[neigh] && dfs(neigh, dest, vis))
                return true;
        }
        return false;
    }

    bool hasPath(int src, int dest) {
        vector<bool> vis(v, false);
        return dfs(src, dest, vis);
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);

    cout << (g.hasPath(0, 6) ? "Path exists" : "No path") << endl;
}
