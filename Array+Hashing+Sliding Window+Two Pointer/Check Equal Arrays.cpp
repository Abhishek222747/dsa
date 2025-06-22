Given two arrays a[] and b[] of equal size, the task is to find whether the 
elements in the arrays are equal.

Two arrays are said to be equal if both contain the same set of elements, arrangements
 (or permutations) of elements may be different though.

Note: If there are repetitions, then counts of repeated elements must also be the same
 for two arrays to be equal.

// User function template for C++

class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mp1,mp2;
        if(a.size()!=b.size()) return false;
        for(int i=0; i<a.size(); i++){
            mp1[a[i]]++;
            mp2[b[i]]++;
        }
        if(mp1==mp2) return true;
        return false;
    }
};