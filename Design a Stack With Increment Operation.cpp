class CustomStack {
public:
    vector<int>stack;
    int top;
    int bottom;
    CustomStack(int maxSize) {
        this->stack.resize(maxSize, -1);
        top = maxSize-1;
        bottom = top;
    }
    
    void push(int x) {
        if(top==-1)
        {
            return;
        }
        stack[top--] = x;
    }
    
    int pop() {
        if(top==bottom)
        {
            return -1;
        }
        int ans = stack[++top];
        stack[top] = -1;
        return ans;
    }
    
    void increment(int k, int val) {
        int i = bottom;
        while(i!=top && k>0)
        {
            stack[i--] += val;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */