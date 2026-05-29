// lowest common ancestor

#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        left=right=NULL;
    }
};

static int idx=-1;

node* buildtree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    node* currnode= new node(nodes[idx]);//1
    currnode->left = buildtree(nodes);//2
    currnode->right = buildtree(nodes);//3
    return currnode;
}

bool rootTonodepath(node *root,int n,vector<int>&path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isleft=rootTonodepath(root->left,n,path);
    int isright=rootTonodepath(root->right,n,path);

    if(isleft || isright){
        return true;
    }

    path.pop_back();
    return false;
}

int lca(node* root, int n1,int n2){
    vector<int>path1;
    vector<int>path2;

    rootTonodepath(root,n1,path1);
    rootTonodepath(root,n2,path2);

    int lca=-1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;
};

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *root=buildtree(nodes);
    
    int n1=4,n2=5;
    cout<<"lca = "<<lca(root,n1,n2)<<endl;
    return 0;
}