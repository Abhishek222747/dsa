Given an array arr[] that contains positive and negative integers (may contain 0 as well).
Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int res=arr[0];
        int mini= arr[0];
        int maxi= arr[0];
        for(int i=1; i<arr.size(); i++){
            int temp= max({arr[i],mini*arr[i],maxi*arr[i]});
            mini= min({arr[i],mini*arr[i],maxi*arr[i]});
            maxi= temp;
            res= max({res,maxi});
        }
        return res;
    }
};