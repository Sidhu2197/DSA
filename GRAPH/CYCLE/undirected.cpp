#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int v;
    list<int> *l;

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void AddEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // undirected graph
    }

    bool cycleHelper(int src, int par, vector<bool>& vis) {
        vis[src] = true;
        list<int> neighbours = l[src];

        for (int node : neighbours) {
            if (!vis[node]) {
                if (cycleHelper(node, src, vis)) {
                    return true;
                }
            }
            else if (node != par) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> vis(v, false);
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (cycleHelper(i, -1, vis)) {
                    return true;
                }
            }
        }
        return false;
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

    cout << (graph.hasCycle() ? "Cycle exists" : "No cycle");

    return 0;
}
