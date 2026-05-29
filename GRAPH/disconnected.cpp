#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int v;              // number of vertices
    list<int> *l;       // adjacency list
    
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void AddEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // undirected graph
    }

    void dfs_helper(int u, vector<bool>& vis) {
        vis[u] = true;
        cout << u << " ";
        for (int neighbour : l[u]) {
            if (!vis[neighbour]) {
                dfs_helper(neighbour, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(v, false);
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs_helper(i, vis);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph graph(10);

    graph.AddEdge(1, 6);
    graph.AddEdge(6, 4);
    graph.AddEdge(4, 3);
    graph.AddEdge(4, 9);
    graph.AddEdge(3, 7);
    graph.AddEdge(2, 0);
    graph.AddEdge(2, 5);

    cout << "DFS Traversal:\n";
    graph.dfs();

    return 0;
}
