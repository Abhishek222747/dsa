Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing 
up the elements of previous row.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> prev={1};
        for(int i=0; i<n; i++){
            vector<int> curr(i+1);
            curr[0]=1;
            for(int j=1; j<i; j++){
                curr[j]= prev[j]+prev[j-1];
            }
            curr[i]=1;
            prev= curr;
        }
        return prev;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends

