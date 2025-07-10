You are given an array arr[] of non-negative integers. Your task is to move all the zeros 
in the array to the right end while maintaining the relative order of the non-zero elements. 
The operation must be performed in place, meaning you should not use extra space for another array.


// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int nonzero=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=0){
                arr[nonzero]= arr[i];
                nonzero++;
            }
        }
        for(int i=nonzero; i<arr.size(); i++){
            arr[i]=0;
        }
    }
};