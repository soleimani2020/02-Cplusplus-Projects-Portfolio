class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }



    int pop() {
        int value = peek();
        output.pop();
        return value;
    }



    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }



    bool empty() {
        return input.empty() && output.empty();
    }


};
