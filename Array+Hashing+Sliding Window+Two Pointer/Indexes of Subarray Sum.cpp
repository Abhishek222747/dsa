Given an array arr[] containing only non-negative integers, your task is to find
a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target.
You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. 
You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].

//hashing one will also work for -ve elements whereas sliding window is only for non negative array.

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here using prefix sum and hashmap
        int n= arr.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        int curr_sum=0;
        for(int i=0; i<n; i++){
            curr_sum+= arr[i];
            if(curr_sum==target){
                ans.push_back(1);
                ans.push_back(i+1);
                return ans;
            }
            if(mp.find(curr_sum-target)!=mp.end()){
            //here mp[any] will give index in 0 based but we need next & 1 based so +2
                ans.push_back(mp[curr_sum-target]+2);
                ans.push_back(i+1);
                return ans;
            }
            mp[curr_sum]=i;
        }
        return {-1};
    }
};



class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int s=0, e=-1;
        int n= arr.size();
        vector<int> ans;
        int curr_sum=0;
        for(int i=0; i<n; i++){
           curr_sum+= arr[i];
           
           if(curr_sum>=target){
               e=i;
               
               while(curr_sum>target && s<e){
                 curr_sum-= arr[s];
                 s++;
               }
               if(curr_sum==target){
                 ans.push_back(s+1);
                 ans.push_back(e+1);
                 return ans;
               }
           }
        }
        return {-1};
    }
};




class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int s=0, e=-1;
        int n= arr.size();
        vector<int> ans;
        int curr_sum=0;
        for(int i=0; i<n; i++){
           curr_sum+= arr[i];
           
           if(curr_sum>=target){
               e=i;
               
               
           }
           while(curr_sum>target && s<e){
                 curr_sum-= arr[s];
                 s++;
               }
               if(curr_sum==target){
                 ans.push_back(s+1);
                 ans.push_back(e+1);
                 return ans;
               }
        }
        return {-1};
    }
};
