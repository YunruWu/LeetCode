/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
 */

class Solution {
public:
    string numberToWords(int num) {
    	string parts[] = {"", " Thousand", " Million", " Billion"};
        string result;
        //int temp = 0;
        if (num == 0) return "Zero";

        int temps[4] = {0};
    	for(int i  = 0; i < 4; ++i){
        	temps[i] = num % 1000;
        	num /= 1000; 
    	}

    	for(int i = 0; i < 4; ++i) {
        	if (temps[i] == 0) continue; 
        	result = helper(temps[i]) + parts[i] + result;  
    	}

        // int count = 0;
        // while (count < 4) {
        // 	temp = num % 1000;
        // 	if (temp == 0) continue;
        // 	result = helper(temp) + parts[count] + result;
        // 	num /= 1000;
        // 	count++;
        // }

    	// return result;
        return result.substr(1); // handle first " " in result
    }

    string helper(int temp) {
    	string individuals[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    	string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    	string result;

    	int digit = temp % 10;
    	int ten = (temp%100) / 10;
    	int hundreds = temp / 100;
    	
    	hundreds == 0 ? result = "" : result = " " + individuals[hundreds] + " Hundred";
    	if (hundreds != 0 && temp%100 == 0) return result;
    	
    	if (temp % 100 < 20) {
    		return result += " " + individuals[temp%100];
    	}
    	else if (temp % 100 > 20 && digit != 0) {
    		return result += " " + tens[ten] + " " + individuals[digit];
    	}
    	else {
    	    return result += " " + tens[ten];
    	}

    }
};