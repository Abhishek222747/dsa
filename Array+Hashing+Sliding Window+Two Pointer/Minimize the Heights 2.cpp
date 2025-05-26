Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and
tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower.
After the operation, the resultant array should not contain any negative integers.



// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
       int n= arr.size();
       sort(arr.begin(),arr.end());
       int res= arr[n-1]-arr[0];
       //add +k from 0 to i-1 then substract k from i to n-1
       for(int i=1; i<n; i++){
           if(arr[i]-k<0) continue;
           int minH= min(arr[0]+k, arr[i]-k);
           int maxH= max(arr[i-1]+k,arr[n-1]-k);
           res= min(maxH-minH, res);
       }
       return res;
    }
};