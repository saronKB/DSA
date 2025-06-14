class MyQueue {
    std::stack<int>box;
    std::stack<int>box2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        box.push(x);

        
    }
    
    int pop() {
        while (!box.empty()){
            box2.push(box.top());
            box.pop();
        }
        int box3=box2.top();
        box2.pop();
       
        while(!box2.empty()){
            box.push(box2.top());
            box2.pop();
        }
         return box3;
    
        
    }
    
    int peek() {
        while(!box.empty()){
            box2.push(box.top());
            box.pop();
        }
        int box3=box2.top();
        
        while(!box2.empty()){
            box.push(box2.top());
            box2.pop();
        }return box3;
        
    }
    
    bool empty() {
        return box.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */