Given an array arr[], where each element is at most k away from its target position, you need to sort the 
array optimally.
Note: You need to change the given array arr[] in place.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n= arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i=k; i<n; i++){
            pq.push(arr[i]);
            arr[i-k]= pq.top();
            pq.pop();
        }
        int j=k-1;  //for last k elemts in the min heap
        while(pq.size()>0){
            arr[n-1-j]= pq.top();
            pq.pop();
            j--;
        }
        return;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends