/*
O(n)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int k = digits.size() - 1; k >= 0; --k) {
            if (digits[k] < 9) { 
                digits[k]++; 
                return digits; 
            } else {
                digits[k] = 0;
            }
        }
        digits[0] = 1, digits.push_back(0);
        return digits;
    }
};
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
       
        if(digits.back() != 9)
        {
        	digits[last]++;
        	return digits;
        }

        int i = last;
        while (i >= 0 && digits[i] == 9)
        {
        	digits[i] = 0;
        	if (i-1 >= 0 && digits[i-1] != 9)
        	{
        		digits[i-1]++;
        		break;
        	}
        	else if (i-1 >= 0 && digits[i-1] == 9)
        		i--;
        	else if (i == 0)
        	{
        		digits.insert(digits.begin(), 1);
        		break;
        	}
        }

        return digits;
    }
};