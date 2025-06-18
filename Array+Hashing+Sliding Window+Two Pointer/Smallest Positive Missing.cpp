You are given an integer array arr[]. Your task is to find the smallest positive 
number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too



class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        unordered_map<int,int> mp;
        int n= arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        int maxi= arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]>maxi){
                maxi= arr[i];
            }
        }
        for(int i=1; i<=maxi+1; i++){
            if(mp[i]<1) return i;
        }
        return 1;
    }
};