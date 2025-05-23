Given an array arr[]. Find the majority element in the array. If no majority element exists,
return -1.

Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times
in the array.


// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
            if(i.second>arr.size()/2){
                return i.first;
                break;
            }
        }
        return -1;
    }
};