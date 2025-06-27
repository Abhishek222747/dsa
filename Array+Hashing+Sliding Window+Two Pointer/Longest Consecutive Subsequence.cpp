Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence
such that elements in the subsequence are consecutive integers, the consecutive numbers can
be in any order.


class Solution {
  private:
    unordered_set<int> st;
    
    int solve(int start){
        int res=0;
        while(st.count(start)){
            start++;
            res++;
        }
        return res;
    }
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        for(int i=0; i<arr.size(); i++){
            st.insert(arr[i]);
        }
        int start=-1;
        int cnt=0;
        for(int i=0; i<arr.size(); i++){
            if(!st.count(arr[i]-1)){
                start= arr[i];
                cnt= max(cnt,solve(start));
            }
        }
        return cnt;
    }
};