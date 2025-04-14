You are given an array arr of size n - 1 that contains distinct integers in the range
from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with
one element missing. Your task is to identify and return the missing element.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // code here
        int n= arr.size()+1;
        int res=0;
        for(int i=0; i<n-1; i++){
            res= res^arr[i];
            res=res^(i+1);
        }
        res= res^(n);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends