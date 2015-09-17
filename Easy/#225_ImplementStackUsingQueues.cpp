class Stack {
public:
    
    deque<int> q;

    // Push element x onto stack.
    void push(int x) {
        q.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop_back();
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};


// using queue
class Stack {
public:
    
    queue<int> q;

    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++) // pay attention to -1
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};