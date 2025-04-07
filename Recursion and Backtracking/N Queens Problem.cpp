The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens
can attack each other. Note that two queens attack each other if they are placed on the same row, 
the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent
a distinct board configuration of the queen placements, where the solutions 
are represented as permutations of [1, 2, 3, ..., n]. In this representation, 
the number in the ith position denotes the row in which the queen is placed in the ith column.



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    void placequeens(int i,vector<int>& columns,vector<int>& leftdiagonals,
    vector<int>& rightdiagonals,vector<int>& curr,vector<vector<int>>& allsolutions){
        //base case
        int n= columns.size();
        if(i==n){
            allsolutions.push_back(curr);
            return;
        } 
        for(int j=0; j<n; j++){
            if(columns[j]||leftdiagonals[i-j+n-1]||rightdiagonals[i+j]) continue;
            columns[j]=1;
            leftdiagonals[i-j+n-1]=1;
            rightdiagonals[i+j]=1;
            curr.push_back(j+1);
            
            placequeens(i+1,columns,leftdiagonals,rightdiagonals,curr,allsolutions);
            
            curr.pop_back();
            columns[j]=0;
            leftdiagonals[i-j+n-1]=0;
            rightdiagonals[i+j]=0;
        }
        
    }
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> columns(n,0);
        vector<int> leftdiagonals(2*n,0);
        vector<int> rightdiagonals(2*n,0);
        vector<int> curr;
        vector<vector<int>> allsolutions;
        placequeens(0,columns,leftdiagonals,rightdiagonals,curr,allsolutions);
        return allsolutions;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends