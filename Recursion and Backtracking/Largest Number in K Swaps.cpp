Given a number k and string s of digits denoting a positive integer, build the largest number
possible by performing swap operations on the digits of s at most k times.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  private:
    void match(string s,string& res){
        if(s>res) res=s;
    }
    void solve(string& s,int index,string& res,int k){
        //base case
        if(k==0||index==s.size()-1){
            match(s,res);
            return;
        }
        int maxdigit=0;
        for(int i=index; i<s.size(); i++){
            maxdigit= max(maxdigit,s[i]-'0');
        }
        if(s[index]-'0'==maxdigit){
            solve(s,index+1,res,k);
            return;
        }
        for(int j=index+1; j<s.size(); j++){
            if(s[j]-'0'==maxdigit){
              swap(s[index],s[j]);
              solve(s,index+1,res,k-1);
              swap(s[index],s[j]);
            }
        }
        
    }
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string res= s;
        solve(s,0,res,k);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends