Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', 
verify the validity of the arrangement.
An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.


class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n= s.size();
        stack<char> st;
        for(int i=0;  i<n; i++){
            if(s[i]=='['||s[i]=='('||s[i]=='{'){
                st.push(s[i]);
            }
            else if(st.size()>0 && 
            ((s[i]==')' && st.top()=='(')||
            (s[i]=='}' && st.top()=='{')||
            (s[i]==']' && st.top()=='['))){
              st.pop();
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};