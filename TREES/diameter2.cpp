// to find max distance from root to leaf

#include <iostream>
#include <vector>
using namespace std;

//code for sum of nodes

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

// build tree from vector (-1 means NULL)
node* buildtree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }

    node* currnode = new node(nodes[idx]);
    currnode->left = buildtree(nodes);
    currnode->right = buildtree(nodes);
    return currnode;
}

// sum of nodes in tree

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int left_height=height(root->left);
    int right_height=height(root->right);

    int currheight= max(left_height,right_height)+1;
    return currheight;
}


int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int currdiameter= height(root->left)+height(root->right)+1;

    int left_diameter=diameter(root->left);
    int right_diameter=diameter(root->right);

    return max(currdiameter,max(left_diameter,right_diameter));
}

//daimter and height
pair<int,int>diameter2(node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    //(diameter,height)
    pair<int,int>leftinfo=diameter2(root->left);//left diameter,left height
    pair<int,int>rightinfo=diameter2(root->right);//right diameter,right height

    int currdiam=leftinfo.second+rightinfo.second+1;
    int finaldia=max(currdiam,max(leftinfo.first,rightinfo.first));
    int finalht=max(leftinfo.second,rightinfo.second)+1;

    return make_pair(finaldia,finalht);

};

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    idx = -1; // reset index before building
    node* root = buildtree(nodes);
    cout<<"diameter : "<<diameter2(root).first<<endl;
    return 0;
}
