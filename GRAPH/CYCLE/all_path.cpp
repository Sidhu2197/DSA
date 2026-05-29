#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int v;
    list<int> *l;
    bool isUndir;

public:
    Graph(int v, bool isUndir = true) {
        this->v = v;
        l = new list<int>[v];
        this->isUndir = isUndir;
    }

    void AddEdge(int u, int v) {
        l[u].push_back(v);
        if(isUndir)
            l[v].push_back(u);
    }

    void pathhelper(int src, int dest, vector<bool>& vis, string& path) {
        if(src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path.push_back(src + '0');
        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                pathhelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size() - 1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(v, false);
        string path = "";
        pathhelper(src, dest, vis, path);
    }
};

int main() {
    Graph graph(6, false);

    graph.AddEdge(0, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 0);
    graph.AddEdge(4, 1);
    graph.AddEdge(5, 0);
    graph.AddEdge(5, 2);

    graph.printAllPaths(5, 1);

    return 0;
}