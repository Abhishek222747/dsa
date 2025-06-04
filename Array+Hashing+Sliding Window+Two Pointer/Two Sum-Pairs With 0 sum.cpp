Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and
 arr[i] + arr[j] == 0.

Note: The pairs must be returned in sorted order, the solution array should also be sorted, 
and the answer must not contain any duplicate pairs.


// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
       unordered_set<int> seen;
       set<vector<int>> ans;
       
       for(int num: arr){
           int complement= -num;
           
           if(seen.count(complement)){
               vector<int> pair= {num, complement};
               sort(pair.begin(), pair.end());
               ans.insert(pair);
           }
           
           seen.insert(num);
       }
       vector<vector<int>> res(ans.begin(), ans.end());
       return res;
    }
};