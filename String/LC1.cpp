You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.

Note: reverse has a void return type, use .pop_back() to remove last char, 
      reverse using string ans(result.rbegin(), result.rend());


class Solution {
public:
    string processStr(string s) {
        string result="";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z') result+= s[i];
            else if(s[i]=='*' && result!="") result.pop_back();
            else if(s[i]=='#') result+= result;
            else if(s[i]=='%') reverse(result.begin(),result.end());
        }
        return result;
    }
};