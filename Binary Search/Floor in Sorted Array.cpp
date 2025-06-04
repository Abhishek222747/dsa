Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element
 in arr[] that is less than or equal to x.
 This element is called the floor of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the last occurrence.


class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int low=0, high= arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(arr[mid]>x){
                high= mid-1;
            }else{
                low= mid+1;
                ans= mid;
            }
        }
        return ans;
    }
};
