#include <stack>
using namespace std;

class MinStack {

private:
    stack<int> st;
    stack<int> min_st;

public:

    MinStack() {
        
    }

    void push(int val) {

        st.push(val);

        if(min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
    }

    void pop() {

        int poppedValue = st.top();
        st.pop();

        if(poppedValue == min_st.top()) {
            min_st.pop();
        }
    }

    int top() {

        return st.top();
    }

    int getMin() {

        return min_st.top();
    }
};
