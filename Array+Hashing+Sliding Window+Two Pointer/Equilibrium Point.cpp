Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements
before that index is the same as the sum of elements after it. Return -1 if no such point exists. 


class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n= arr.size();
        int prefix[n];
        prefix[0]= arr[0];
        for(int i=1; i<n; i++){
           prefix[i]= arr[i]+prefix[i-1];
        }
        for(int i=1; i<n; i++){
           if((prefix[n-1]-prefix[i])==prefix[i-1]) return i;
        }
        return -1;
    }
};