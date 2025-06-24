Given a string s, reverse the string without reversing its individual words. Words are 
separated by spaces.

Note: The string may contain leading or trailing spaces, or multiple spaces between two words.
 The returned string should only have a single space separating the words, and no extra spaces
 should be included.



class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {
        // code here
        string p="";
        stack<string> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                if(p.size()>0){
                    st.push(p);
                    p="";
                }
            }
            else{
                p+= s[i];
            }
        }
        if(p.size()>0){
          st.push(p);
        }
        string ans="";
        while(st.size()>0){
            ans+= st.top();
            st.pop();
            if(st.size()>0) ans+= " ";
        }
        return ans;
    }
};