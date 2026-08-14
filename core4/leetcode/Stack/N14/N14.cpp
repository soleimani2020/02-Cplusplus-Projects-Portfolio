class MaxStack {
private:
    stack<int> st;
    stack<int> maxSt;   // stores the maximum value up to each level

public:
    MaxStack() {}
    
    void push(int x) {
        st.push(x);
        if (maxSt.empty() || x >= maxSt.top())
            maxSt.push(x);
        else
            maxSt.push(maxSt.top());
    }
    
    int pop() {
        maxSt.pop();
        int val = st.top();
        st.pop();
        return val;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return maxSt.top();
    }
    
    int popMax() {
        int maxVal = peekMax();
        stack<int> temp;
        // Move elements above the topmost maximum to a temporary stack
        while (top() != maxVal) {
            temp.push(pop());
        }
        // Remove the maximum
        pop();
        // Restore the elements
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        return maxVal;
    }
};
