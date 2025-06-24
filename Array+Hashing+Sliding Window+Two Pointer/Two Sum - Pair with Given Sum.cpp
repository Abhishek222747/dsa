Given an array arr[] of positive integers and another integer target. Determine if there exist 
two distinct indices such that the sum of their elements is equal to the target.

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++){
            int rem= target-arr[i];
            if(mp.find(rem)!=mp.end()){
                return true;
            }
            else{
                mp[arr[i]]=i;
            }
        }
        return false;
    }
};