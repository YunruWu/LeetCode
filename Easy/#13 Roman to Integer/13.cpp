/*
O(n)
 */

class Solution {
public:
    int romanToInt(string s) {
    	unordered_map<char, int> symbol_val { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    	
    	int result = symbol_val[s[s.length()-1]];
    	int temp = result;
    	for (int i = s.length()-2; i >= 0; i--)
    	{
    		// traverse from the end
    		char symbol = s[i];
    		if (symbol_val[symbol] < temp)
    			result -= symbol_val[symbol];  // for 'IV' etc...
    		else
    			result += symbol_val[symbol];
    		temp = symbol_val[symbol];
    	}

    	return result;
    }
};