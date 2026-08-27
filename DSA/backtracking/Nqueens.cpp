#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    bool isSafe1(int row,int col,vector<string>&board,int n)
    {
        // check upper diagonal 
        int duprow=row;
        int dupcol=col;
        while(row>=0&&col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;

            
        }
        col=dupcol;
        row=duprow;
        {
            while(col>=0){
                if (board[row][col]=='Q') return false;
                col --;

            }
            row=duprow;
            col=dupcol;
            while(row<n&&col>=0){
                if(board[row][col]=='Q') return false;
                row++;
                col--;

            }
            return true;
            
        }
    }
           
        
        public:
        void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
            if(col==n){
                ans.push_back(board);
                return;
            }
             for (int row=0;row<n;row++){
                if(isSafe1(row,col,board,n)){
                    board[row][col]='Q';
                    solve(col+1,board,ans,n);
                    board[row][col]='.';

                }
             }
            
        }
        public:
        vector<vector<string>>solveNQueens(int n){
            vector<vector<string>>ans;
            vector<string>board(n);
            string s(n,'.');
            for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};/*
    The N-Queens problem is the challenge of placing N chess queens on an N×N chessboard 
    such that no two queens attack each other. This solution uses backtracking to 
    explore all possible placements column by column.
    */


int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (const auto& board : result) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
};
    