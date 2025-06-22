Given an array arr containing both positive and negative integers, the task
 is to compute the length of the largest subarray that has a sum of 0.

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n= arr.size();
        unordered_map<int,int> mp;
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= arr[i];
            if(sum==0) ans= i+1;
            
            if(mp.find(sum)!=mp.end()){
                ans= max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};