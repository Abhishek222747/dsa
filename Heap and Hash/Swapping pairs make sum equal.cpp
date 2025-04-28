Given two arrays of integers a[] and b[], the task is to check if a pair of values
(one value from each array) exists such that swapping the elements of the pair will
 make the sum of two arrays equal.

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        long long sum1=0,sum2=0;
        for(auto i:a) sum1+= i;
        for(auto i:b) sum2+= i;
        //sum1-x+y==sum2-y+x  return true;
        //x= (sum1-sum2)/2+y;
        unordered_map<int,int> mp;
        for(int i=0; i<a.size(); i++){
            mp[a[i]]++;
        }
        if((sum1-sum2)%2!=0) return false;
        for(int i=0; i<b.size(); i++){
          long long num= (long long)(sum1-sum2)/2+b[i]; //this is equal to x
          if(mp[num]>0) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        // d = crr[0];
        int n = arr.size();
        Solution ob;
        bool ans = ob.findSwapValues(arr, crr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends