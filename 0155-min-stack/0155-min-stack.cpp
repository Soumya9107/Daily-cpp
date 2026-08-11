class MinStack {
private:
    vector<int> myStack;
    vector<int> minStack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push_back(val);
        if(minStack.empty()){ minStack.push_back(val); }
        else{
            val = min(val, minStack.back());
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if(myStack.empty() && minStack.empty()){
            return;
        }
        myStack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        if(myStack.empty()){ return -1; }
        return myStack.back();
    }
    
    int getMin() {
        if(minStack.empty()){ return -1; }
        return minStack.back();
    }
};
