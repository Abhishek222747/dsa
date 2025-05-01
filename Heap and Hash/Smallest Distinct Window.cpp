Given a string str, your task is to find the length of the smallest window that
 contains all the characters of the given string at least once.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
       unordered_set<char> unique_char(str.begin(),str.end());
       int unique= unique_char.size();
       int i=0,j=0;
       int small_len=INT_MAX;
       int count=0;
       unordered_map<char,int> mp;
       while(j<str.size()){
           mp[str[j]]++;
           if(mp[str[j]]==1) count++;  //means unique element
           
           //shrink till contains all characters atleast once
           while(count==unique){
              small_len= min(small_len,j-i+1);  //calculate most small window
              mp[str[i]]--;
              if(mp[str[i]]==0) count--;  //remove from total unique chars in small window
              i++;
           }
           j++;
       }
       return small_len;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends