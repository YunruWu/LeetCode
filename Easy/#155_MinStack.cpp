/*
O(n)
 */

class MinStack {
public:
	deque<int> minStack;
	deque<int> mins;

    void push(int x) {
        minStack.push_back(x);
        if (mins.size() == 0 || x <= mins.back()) 
        	mins.push_back(x);
    }

    void pop() {
        int top = minStack.back();
        minStack.pop_back();
        if (top <= mins.back())
        	mins.pop_back();
    }

    int top() {
        return minStack.back();
    }

    int getMin() {
        return mins.back();
    }
};