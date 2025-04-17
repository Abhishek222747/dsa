Given an array, arr[] of rope lengths, connect all ropes into a single rope with 
the minimum total cost. The cost to connect two ropes is the sum of their lengths. 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n= arr.size();
        if(n<2) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        int ans=0,curr=0;
        while(pq.size()>1){
            int a= pq.top();
            pq.pop();
            curr+= a;
            ans+=a;
            
            int b= pq.top();
            pq.pop();
            curr+= b;
            ans+= b;
            pq.push(curr);
            curr=0;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends