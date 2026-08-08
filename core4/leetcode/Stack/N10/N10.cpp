class StockSpanner {
public:

    vector<int> prices;
    stack<int> st;  // stores indices

    StockSpanner() {}

    int next(int price) {

        // Current index
        int i = prices.size();

        // Store current price
        prices.push_back(price);

        // Remove previous prices <= current price
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int span;

        if (st.empty()) {
            // No previous greater price
            span = i + 1;
        }
        else {
            // Previous greater price is at st.top()
            span = i - st.top();
        }

        // Store current index
        st.push(i);

        return span;
    }
};
