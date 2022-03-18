class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        push_stack.push(x);
    }
    
    int pop() {
        
        int top;
        // if pop stack is empty;
        if(pop_stack.empty()){
            
            while(!push_stack.empty()){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
            
        }
        top = pop_stack.top();
        pop_stack.pop();
        
        return top;
    }
    
    int peek() {

        // if pop stack is empty;
        if(pop_stack.empty()){
            
            while(!push_stack.empty()){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        
        return pop_stack.top();
    }
    
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
    }
private:
    stack<int> push_stack;
    stack<int> pop_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
