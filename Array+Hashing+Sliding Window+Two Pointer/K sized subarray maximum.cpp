Given an array arr[] of integers and an integer k, your task is to find the maximum value for
 each contiguous subarray of size k. The output should be an array of maximum values corresponding
 to each contiguous subarray.


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        deque<int> dq(k);
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k; i<arr.size(); i++){
            res.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front()<= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        return res;
    }
};