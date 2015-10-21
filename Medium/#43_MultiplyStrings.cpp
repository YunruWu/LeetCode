/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
 */

/*
We use two nested for loops, working backward from the end of each input number. 
We pre-allocate our result and accumulate our partial result in there. 
One special case to note is when our carry requires us to write to our sum string outside of our for loop.

At the end, we trim any leading zeros, or return 0 if we computed nothing but zeros.
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string result(num1.length()+num2.length(), '0');

        for (int i = num1.length() - 1; i >= 0; i--) {
        	int carry = 0;
        	for (int j = num2.length() -1; j >= 0; j--) {
        		int temp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
        		result[i + j + 1] = temp % 10 + '0';
        		carry = temp / 10;
        	}
        	result[i] += carry; // what left is result[i] for carry
        }

        return result.substr(result.find_first_not_of("0"));
    }
};