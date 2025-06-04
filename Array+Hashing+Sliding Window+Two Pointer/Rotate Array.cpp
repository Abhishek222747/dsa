Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps,
 where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n= arr.size();
        d= d%n;
        if(d ==0) return;
        reverse(arr.begin(), arr.begin()+d);
        reverse(arr.begin()+d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};