#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int v;
    list<int>*l;
    public:

    Graph(int v){
        this->v=v;
        l=new list<int>[v];
    }

    void AddEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    void dfs_helper(int u,vector<bool>&vis) {
        
        vis[u]=true;
        cout<<u<<" ";

        list<int>neighbour=l[u];
        for(int v : neighbour){
            if(!vis[v]){
                dfs_helper(v,vis);
            }
        }
    }

    void dfs(){
        vector<bool>vis(7,false);
        dfs_helper(0,vis);
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

    cout << "DFS Traversal: ";
    graph.dfs();
    return 0;
}
