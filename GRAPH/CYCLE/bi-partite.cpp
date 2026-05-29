#include <iostream>
#include <list>
#include <queue>
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

    bool isBipartite(){
        queue<int>q;
        vector<int>colour(v,-1);

        q.push(0);
        colour[0]=0;

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int>neighbours=l[curr];

            for(int v : neighbours){
                if(colour[v]== -1){
                    colour[v]=!colour[curr];
                    q.push(v);
                }
                else {
                    if(colour[v] == colour[curr]){
                        return false;
                    }
                }
            }
        }
        return true;   // ✅ fix 2
    }
};

int main() {
    Graph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    cout << (graph.isBipartite() ? "yes the given graph is a bi-partite graph" : "no the given graph is not a bi-partite graph")<<endl;

    return 0;
}
