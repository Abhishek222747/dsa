Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][],
the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed
and cannot be changed.



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool isSafe(int num,vector<vector<int>> &mat,int row,int col){
        int n= mat.size();
        int m= mat[0].size();
        //check row
        for(int j=0; j<m; j++){
            if(mat[row][j]==num) return false;
        }
        //check col
        for(int i=0; i<n; i++){
            if(mat[i][col]==num) return false;
        }
        //check 3*3 box
        int startrow= row-row%3,startcol= col-col%3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(mat[i+startrow][j+startcol]==num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>> &mat,int row,int col){
        int n= mat.size();
        int m= mat[0].size();
        if(row==n-1 && col==m) return true;
        if(col==m){
            row++;
            col=0;
        }
        //if space is occupied, move forward
        if(mat[row][col]!=0) return solve(mat,row,col+1);
        //check for each number from 1 to 9
        for(int i=1; i<=n; i++){
            if(isSafe(i,mat,row,col)){
                mat[row][col]=i;
                if(solve(mat,row,col+1)) return true;
                mat[row][col]=0;
            }
        }
        return false;
    }
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat,0,0);
    }
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends