/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

遇到 '(' 就把之前的结果和符号push进stack. 遇到')'就把 当前结果*stack中的符号 再加上stack中之前的结果
 */

class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int num = 0, result = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
        	char c = s[i];
        	if (isdigit(c)) {
        		num = num * 10 + c - '0';  // store current number
        	}
        	else {
        		result += num * sign;
        		num = 0;
        		if (c == '+') sign = 1;
        		if (c == '-') sign = -1;
        		if (c == '(') {
        			nums.push(result);
        			ops.push(sign);
        			result = 0;
        			sign = 1;
        		}
        		if (c == ')') {
        			result = result * ops.top() + nums.top();
        			ops.pop();
        			nums.pop();
        		}
        	}
        }

        result += num * sign;
        return result;
    }
};