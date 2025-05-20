Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        //if adding curr_ele makes things bigger add else start again
        int n= arr.size();
        int curr_sum= arr[0];
        int max_sum= arr[0];
        for(int i=1; i<n; i++){
           curr_sum= max(arr[i],curr_sum+arr[i]);
           max_sum= max(max_sum,curr_sum);
        }
        return max_sum;
    }
};