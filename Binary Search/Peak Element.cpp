Given an array arr[] where no two adjacent elements are same, find the index of a peak element.
An element is considered to be a peak if it is greater than its adjacent elements (if they exist).
If there are multiple peak elements, return index of any one of them. The output will be "true" if 
the index returned by your function is correct; otherwise, it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative
infinity.


class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n= arr.size();
        if(n==1) return 0; //0th index return
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        int l=1, h=n-2;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            
            if(arr[mid]<arr[mid+1]){
                l= mid+1;
            }
            else{
                h= mid-1;
            }
        }
        return 0;
    }
};