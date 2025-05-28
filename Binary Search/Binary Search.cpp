Given a sorted array arr and an integer k, find the position(0-based indexing) at
 which k is present in the array using binary search.

Note: If multiple occurrences are there, please return the smallest index.

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int low=0, high= arr.size()-1;
        int result= -1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(arr[mid]==k){
                result= mid;
                high=mid-1;
            }else if(arr[mid]<k){
                low= mid+1;
            }else{
                high= mid-1;
            }
        }
        return result;
    }
};