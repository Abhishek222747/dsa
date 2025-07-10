Determine the sequence after removing the redundant nodes with similar configuration. 
Maintain the dependency order. Choose the lexicographically larger sequence, incase of
multiple possible sequences.

Input: AZADA
Output: ZDA

Input: AZAD
Output: ZAD

Input: ZAZDA
Output: ZDA



string getLargestUniqueSequence(string s) {
    unordered_map<char, int> lastIndex;
    for (int i = 0; i < s.size(); ++i)
        lastIndex[s[i]] = i;

    stack<char> st;
    unordered_set<char> seen;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (seen.count(c)) continue;

        while (!st.empty() && c > st.top() && lastIndex[st.top()] > i) {
            seen.erase(st.top());
            st.pop();
        }

        st.push(c);
        seen.insert(c);
    }

    // Build result
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
