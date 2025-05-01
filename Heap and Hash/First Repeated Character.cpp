Given a string s. The task is to find the first repeated character in it. 
We need to find the character that occurs more than once and whose index 
of second occurrence is smallest. s contains only lowercase letters.

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        string ans= "-1";
        unordered_map<int,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                ans= s[i];
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
//    Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.firstRepChar(str) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends