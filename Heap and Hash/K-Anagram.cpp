Two strings are called k-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most k characters in a string.

Given two strings of lowercase alphabets and an integer value k, the task is to
find if two strings are k-anagrams of each other or not.


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // code here
        if(s1.size()!=s2.size()) return false;
        unordered_map<char,int> mp;
        for(int i=0; i<s1.length(); i++){
            mp[s1[i]]++;
        }
        int cnt=0;
        for(int i=0; i<s2.length(); i++){
           if(mp[s2[i]]>0){
               mp[s2[i]]--;
               cnt++;
           }
        }
        int change= s2.length()-cnt;
        if(change>k) return false;
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        int k;
        cin >> k;
        Solution ob;
        if (ob.areKAnagrams(str1, str2, k) == true)
            cout << "true\n";
        else
            cout << "false\n";
    }
}
// } Driver Code Ends