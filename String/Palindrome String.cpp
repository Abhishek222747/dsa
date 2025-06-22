You are given a string s. Your task is to determine if the string is a palindrome. 
A string is considered a palindrome if it reads the same forwards and backwards.

class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
};