Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether
two given strings are an anagram of each other or not. An anagram of a string is another string
that contains the same characters, only the order of characters can be different. 
For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 can only contain 
lowercase alphabets.

Note: You can assume both the strings s1 & s2 are non-empty.

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int n= s1.size();
        int m= s2.size();
        if(n!=m) return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0; i<n; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp1[s1[i]]!=mp2[s1[i]]) return false;
        }
        return true;
    }
};