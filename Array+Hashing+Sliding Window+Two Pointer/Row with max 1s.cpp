You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is
 sorted in non-decreasing order. Your task is to find and return the index of the first row that
 contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.


// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n= arr.size();
        int m= arr[0].size();
        int i=0, j=m-1;
        int row=-1;
        while(i<n && j>=0){
            if(arr[i][j]==1){
                row=i;
                j--;
            }
            else{
                i++;
            }
        }
        return row;
    }
};