Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is
from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 


class Solution {
  private:
    int countAndMerge(vector<int>& arr, int l, int m, int r) {
  
      // Counts in two subarrays
      int n1 = m - l + 1, n2 = r - m;

      // Set up two vectors for left and right halves
      vector<int> left(n1), right(n2);
      for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
      for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
      int res = 0;
      int i = 0, j = 0, k = l;
      while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i 
      	// elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
      }

    // Merge remaining elements
      while (i < n1)
        arr[k++] = left[i++];
      while (j < n2)
        arr[k++] = right[j++];

      return res;
    }


    int countInv(vector<int>& arr, int l, int r){
      int res = 0;
      if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and 
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in 
      	// the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
      }
      return res;
    }
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n= arr.size();
        return countInv(arr, 0, n - 1);
    }
};