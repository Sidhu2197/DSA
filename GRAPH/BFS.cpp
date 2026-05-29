#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
        l[v].push_back(u);   // undirected (both ways)
    }

    string bfs() {
        vector<bool> vis(v, false);
        queue<int> q;
        string result = "";

        for (int start = 0; start < v; start++) {   // covers disconnected graph also
            if (!vis[start]) {
                q.push(start);
                vis[start] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    result += to_string(u) + " ";
                    
                    for (int nbr : l[u]) {
                        if (!vis[nbr]) {
                            vis[nbr] = true;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Graph graph(7);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 4);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 5);
    graph.AddEdge(5, 6);

    cout << "BFS Traversal: " << graph.bfs() << endl;

    return 0;
}
