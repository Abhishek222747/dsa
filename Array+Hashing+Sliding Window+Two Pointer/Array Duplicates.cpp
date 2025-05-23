Given an array arr of integers, find all the elements that occur more than once 
in the array. If no element repeats, return an empty array.


class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<int> ans;
        for(auto i:mp){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;
    }
};