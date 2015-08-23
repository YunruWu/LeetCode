/*
O(n)
 */

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for (int i = 0; i < s.length(); i++){
        	switch (s[i]){
        		case '(':
        		case '[':
        		case '{':
        			bracket.push(s[i]);
        			break;
        		case ')':
					if (bracket.size() == 0 || bracket.top() != '(')
						return false;
					bracket.pop();
					break;
				case ']':
					if (bracket.size() == 0 || bracket.top() != '[')
						return false;
					bracket.pop();
					break;
				case '}':
					if (bracket.size() == 0 || bracket.top() != '{')
						return false;
					bracket.pop();
					break;
        	}
        } 
        
        // handle "(" or "[" or "{"
        return (bracket.size() == 0);
    }
};