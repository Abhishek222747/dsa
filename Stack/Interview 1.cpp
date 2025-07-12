Problem Statement: Online Stock Span (Modified Version)
You are given an array prices[] of size n representing stock prices over n days.

For each day i (0-indexed), you must compute the stock span, which is the number of consecutive
 days (including today) the price has been less than or equal to the price on day i.

That is, for each i, span[i] = max number of consecutive days before or at i such 
that prices[j] <= prices[i]


//1st solution

vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n, 1);

    for (int i = 0; i < n; ++i) {
        int j = i - 1;
        while (j >= 0 && prices[j] <= prices[i]) {
            span[i]++;
            j--;
        }
    }
    return span;
}


//2nd solution
vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<pair<int, int>> st; // pair of (price, index)

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first <= prices[i]) {
            st.pop();
        }

        // If stack is empty, span is i+1 (all previous are <=)
        // Else, span = i - previous greater element's index
        span[i] = st.empty() ? (i + 1) : (i - st.top().second);

        st.push({prices[i], i});
    }
    return span;
}
