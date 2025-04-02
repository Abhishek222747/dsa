Given an array arr[], determine if it can be partitioned into two subsets such that 
the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 200



//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool solve(vector<int>& arr,int target,int index,vector<vector<int>>& dp){
        if(target==0) return true;
        if(target<0 || index>=arr.size()) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        //including the element
        bool include= false;
        if(arr[index]<=target){
           include= solve(arr,target-arr[index],index+1,dp);
        }
        //excliding the element
           bool exclude= solve(arr,target,index+1,dp);
            
        return dp[index][target]= include||exclude;
    }
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n= arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        if(sum%2) return false;
        return solve(arr,sum/2,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends