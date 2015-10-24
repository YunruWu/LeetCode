/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

 */

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if (numerator == 0) return "0";
        if (numerator < 0 ^ denominator < 0) {  // ^ is XOR
        	result += '-';
        } 

        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        result += to_string(integral);

        long rmd = numer % denom;
        if (!rmd) return result;
        result += '.';
        rmd *= 10; // 除不尽除数加0

        unordered_map<long, int> mp;
        while (rmd) {
        	long temp_intergral = rmd / denom;
         	if (mp.find(rmd) != mp.end()) {
         		result.insert(mp[rmd], 1, '(');
         		result += ')';
				break;
         	}
         	else {
         		mp[rmd] = result.length();
         		result += to_string(temp_intergral);
         		rmd = (rmd % denom) * 10;
         	}
        }

        return result;
    }
};