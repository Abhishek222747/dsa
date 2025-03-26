Given a string s, which may contain duplicate characters, your task is to generate and 
return an array of all unique permutations of the string. You can return your answer in any order.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void findpermut(int index,string &s,set<string>&ans){
        //base case
        if(index==s.size()){
            ans.insert(s);
            return;
        }
        
        for(int i=index; i<s.size(); i++){
            swap(s[index],s[i]);
            findpermut(index+1,s,ans);
            swap(s[index],s[i]);
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> ans;
        findpermut(0,s,ans);
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends