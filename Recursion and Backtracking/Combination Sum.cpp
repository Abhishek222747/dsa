Given an array arr[] and a target, your task is to find all unique combinations in the array where 
the sum is equal to target. The same number may be chosen from the array any number of times to make target.

You can return your answer in any order.

Examples:

Input: arr[] = [2, 4, 6, 8], target = 8
Output: [[2 2 2 2] [2 2 4] [2 6] [4 4] [8]]
Explanation: Total number of possible combinations are 5.
Input: arr[] = [2, 7, 6, 5], target = 16
Output: [[2 2 2 2 2 2 2 2] [2 2 2 2 2 6] [2 2 2 5 5] [2 2 5 7] [2 2 6 6] [2 7 7] [5 5 6]]
Explanation: Total number of possible combinations are 7.
Input: arr[] = [6, 5, 7], target = 8
Output: []
Explanation: There are no possible combinantions such that target sum is 8.
Constraints:
1 <= arr.size() <= 30
2 <= arr[i] <= 40
2 <= target <= 40
All arr[i] are distinct.



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  private:
    void solve(vector<int> &arr,int remsum,vector<int>& curr,vector<vector<int>>& res,int index){
        if(remsum==0){
            res.push_back(curr);
            return;
        }
        if(remsum<0 || index>=arr.size()) return;
        //include the element
        curr.push_back(arr[index]);
        solve(arr,remsum-arr[index],curr,res,index);
        
        curr.pop_back();
        //skip the element
        solve(arr,remsum,curr,res,index+1);
        
    }
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        vector<int> curr;
        vector<vector<int>> res;
        solve(arr,target,curr,res,0);
        return res;
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends