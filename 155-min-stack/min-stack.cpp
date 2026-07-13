class MinStack {
    stack<long long>s;
    long long m;
public:
    MinStack() {
        m=0;
    }
    
    void push(int value) {
        if(s.empty())
        {
            s.push(value);
            m=value;
        }
        else
        {
            if(value>=m)
            s.push(value);
            else
            {
                s.push(2LL*value-m);
                m=value;
            }
        }
    }
    
    void pop() {
        if(s.empty())
        return ;
        long long p=s.top();
        s.pop();
        if(p<m)
        m=2*m-p;
    }
    
    int top() {
        if(s.top()<m)
        return m;
        return s.top();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */