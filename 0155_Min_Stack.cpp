struct Mynode {
    int val;
    int min;
    Mynode *next;
    
    Mynode(int x,int m) : val(x), min(m), next(nullptr) {}
    Mynode(int x, int m, Mynode *next) : val(x), min(m), next(next) {}
};

class MinStack {
private:
    Mynode *head = nullptr;
    
public:
    void push(int x) {
        if (head == nullptr) 
            head = new Mynode(x, x);
        else 
            head = new Mynode(x, min(x, head -> min), head);
    }
    
    void pop() {
        head = head -> next;
    }
    
    int top() {
        return head -> val;
    }
    
    int getMin() {
        return head -> min;
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
