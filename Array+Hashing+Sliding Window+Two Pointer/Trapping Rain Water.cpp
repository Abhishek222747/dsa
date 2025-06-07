Given an array arr[] with non-negative integers representing the height of blocks. 
If the width of each block is 1, compute how much water can be trapped between the 
blocks during the rainy season. 

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<int> left(n), right(n);
        left[0]=arr[0];
        right[n-1]= arr[n-1];
        for(int i=1; i<n; i++){
            left[i]= max(left[i-1],arr[i]);
        }
        for(int i=n-2; i>=0; i--){
            right[i]= max(right[i+1],arr[i]);
        }
        int trapped_water=0;
        for(int i=1; i<n-1; i++){
            int water= min(left[i], right[i])-arr[i];
            trapped_water+= max(0,water);
        }
        return trapped_water;
    }
};