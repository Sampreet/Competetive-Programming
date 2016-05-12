class Queue {
    stack<int> temp;
    stack<int> val;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(val.empty()){
            val.push(x);
        }else{
            while(!val.empty()){
                temp.push(val.top());
                val.pop();
            }

            val.push(x);

            while(!temp.empty()){
                val.push(temp.top());
                temp.pop();
            }
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        val.pop();
    }

    // Get the front element.
    int peek(void) {
        return val.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return val.empty();
    }
};
