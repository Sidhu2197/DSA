#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<list>
using namespace std;


class Graph {
    int v;
    list<int> *l;
    bool isUndirc;

public:
    Graph(int v,bool isUndirc = true) {
        this->v = v;
        l = new list<int>[v];
        this->isUndirc=isUndirc;
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        if(isUndirc)
        l[v].push_back(u);
    }

    void topohelper(int i, vector<bool>&vis,stack<int>&s){//dfs
        vis[i]=true;

        list<int>neighbours=l[i];
        for(int v :neighbours){
            if(!vis[v]){
                topohelper(v,vis,s);
            }
        }
        s.push(i);

    }

    void topo(){
        vector<bool>vis(v,false);
        stack<int>s;

        for(int i=0;i<v;i++){
            if(!vis[i])
            {
                topohelper(i,vis,s);
            }
        }
        // for printing of topological sort
        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};

int main(){
    // DAG
    Graph graph(6,false);
    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topo();
    return 0;
}