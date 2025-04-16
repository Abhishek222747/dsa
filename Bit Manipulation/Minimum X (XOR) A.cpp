Given two integers A and B, the task is to find an integer X such that (X XOR A)
is minimum possible and the count of set bit in X is equal to the count of set bits in B.


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cnt_b= __builtin_popcount(b);
        int cnt_a= __builtin_popcount(a);
        int ans=0;
        for(int i=0; i<=31; i++){
            int mask= 1<<i;
            int set= a&mask;
        //if a is 0 at this ith bit and set bits in X requires greater than a
            if(set==0 && cnt_b>cnt_a){
                ans |= mask; //add 1 to use cnt_b to make equal to X
                cnt_b--;
            }
        //if a is 1 at this ith bit and set bits in X requires lesser than a
            else if(set && cnt_b<cnt_a){
                cnt_a--;  //a is 1 and greater just skip to only deal with cnt_b
            }
        //when setbits in a and b are equal keep adding same as a's bit to minimize X^A
            else{
                ans |= set;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends