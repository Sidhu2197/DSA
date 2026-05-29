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
        l[u].push_back(v);  // directed edge
    }

    bool cycleHelper(int src, vector<bool>& vis, vector<bool>& recpath) {
        vis[src] = true;
        recpath[src] = true;

        for (int node : l[src]) {
            if (!vis[node]) {
                if (cycleHelper(node, vis, recpath)) return true;
            }
            else if (recpath[node]) {
                return true; // back edge → cycle
            }
        }

        recpath[src] = false;
        return false;
    }

    bool hasCycle() {
        vector<bool> vis(v, false);
        vector<bool> recpath(v, false);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (cycleHelper(i, vis, recpath)) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);

    g.AddEdge(1, 0);
    g.AddEdge(0, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 0);

    cout << "Directed Graph has cycle? " << (g.hasCycle() ? "Yes" : "No") << endl;

    return 0;
}
