class MinStack {
public:
    stack<pair<int,int>> stack;
    MinStack() {
        ///stack<pair<int,int>> stack;
    }
    
    void push(int val) {
        int new_min=stack.empty()? val: min(val,stack.top().second);
        stack.push({val,new_min});
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
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