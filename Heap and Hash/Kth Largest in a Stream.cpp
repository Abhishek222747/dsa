Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element)
 after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer
 will be -1 for that insertion.  return a list of size n after all insertions.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> ans;
        //create a min heap of size k
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<n; i++){
            if(pq.size()<k){
                pq.push(arr[i]); //this will fill k elements
            }
            else{
                if(arr[i]>pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            
            //if size is less than k
            if(pq.size()<k) ans.push_back(-1);
            else{
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends