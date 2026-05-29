#include<iostream>
#include<string>
#include<vector>
using namespace std;


void printboard(vector<vector<char>>board){
    int n=board.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------------\n"<<endl;
    
}

bool isSafe(vector<vector<char>>board,int row,int col){
    int n=board.size();
    
    for(int i=0;i<row;i++){
        if(board[i][col]=='q'){
            return false;
        }
    }
    
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='q'){
            return false;
        }
    }
    
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='q'){
            return false;
        }
    }
    
    return true;
}

//ith row-> ith queen
void nqueens(vector<vector<char>>board,int row){
int n=board.size();
if(row==n){
    printboard(board);
    return;
}


for(int j=0;j<n;j++){
    if(isSafe(board,row,j)){
        board[row][j]='q';
        nqueens(board,row+1);
        board[row][j]='.';   //backtracking
    }
}
}

int main(){
    vector<vector<char>> board;
    int n=5;

    for(int i=0;i<n;i++){
        vector<char>newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    nqueens(board,0);
    return 0;
}