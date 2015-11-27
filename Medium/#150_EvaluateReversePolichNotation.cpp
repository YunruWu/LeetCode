/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        
        stack<int> nums;
        int num1, num2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].size() > 1 || isdigit(tokens[i][0])) {
                nums.push(stoi(tokens[i]));
            }
            else {
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                if (tokens[i][0] == '+') num1 += num2;
                else if (tokens[i][0] == '-') num1 -= num2;
                else if (tokens[i][0] == '*') num1 *= num2;
                else if (tokens[i][0] == '/') num1 /= num2;
                nums.push(num1);
            }
            //nums.push(num1);
        }
        
        return nums.top();
    }
};