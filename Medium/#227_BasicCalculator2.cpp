/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 */

// using two stacks
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        s.push_back(')');
        ops.push('+');
        
        int num = 0, result = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
        	if (isdigit(s[i])) {
        		num = num * 10 + s[i] - '0';  // store current number
        	}
        	else if (s[i] == ' ') continue;
        	else {
        		if (ops.top() == '*' || ops.top() == '/') {
        			num = ops.top() == '*' ? nums.top()*num : nums.top()/num;
        			ops.pop();
        			nums.pop();
        		}
        		nums.push(num);
        		num = 0;
        		ops.push(s[i]);
        	}
        }
        
       ops.pop();
       while (!ops.empty()) {
       		ops.top() == '+' ? sign = 1: sign = -1;
       		result += nums.top() * sign;
       		ops.pop();
       		nums.pop();
       }

       return result;
    }
};


/*
O(n) time, O(1) space. 
Every time I got a number, I will aggregate it into the current result.
when I met '+' or '-", current result will be aggregated into the final result sum.
 */
class Solution {
public:
    int calculate(string s) {
        int result = 0, cur_res = 0;
        char op = '+';
        for(int pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {
            if(isdigit(s[pos])) {
                int tmp = s[pos] - '0';
                while(++pos < s.size() && isdigit(s[pos]))
                    tmp = tmp*10 + (s[pos] - '0');
                switch(op) {
                    case '+' : cur_res += tmp; break;
                    case '-' : cur_res -= tmp; break;
                    case '*' : cur_res *= tmp; break;
                    case '/' : cur_res /= tmp; break;
                }
            }
            else {
                if(s[pos] == '+' || s[pos] == '-') {
                    result += cur_res;
                    cur_res = 0;
                }
                op = s[pos++];
            }
        }
        return result + cur_res;
    }
};