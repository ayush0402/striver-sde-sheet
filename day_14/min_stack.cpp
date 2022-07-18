// O(2N) Space complexity

class MinStack {
public:
    stack <pair<int, int>> st;
    MinStack() {

    }

    void push(int val) {
        int minn = val;
        if (!st.empty())
            minn =  min(minn, st.top().second);
        st.push({val, minn});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// O(N) Space complexity
