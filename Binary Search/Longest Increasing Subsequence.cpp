Given an array arr[] of non-negative integers, the task is to find the length of the Longest 
Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than
 the next element.


//solution 1

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int> dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i]){
                    dp[i]= max(dp[i],dp[j]+1);
                }
            }
        }
        int ans= *max_element(dp.begin(),dp.end());
        return ans;
    }
};


//solution 2

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int> temp;
        for(int i=0; i<arr.size(); i++){
            auto it= lower_bound(temp.begin(),temp.end(),arr[i]);
            if(it==temp.end()){
                temp.push_back(arr[i]);
            }
            else{
                *it=arr[i];
            }
        }
        return temp.size();
    }
};