class MyStack {
public:

    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 1; i < n; i++) {
            int value = q.front();
            q.pop();
            q.push(value);
        }
    }

    int pop() {
        int value = q.front();
        q.pop();

        return value;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
