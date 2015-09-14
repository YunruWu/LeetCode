/*
O(n)
 */

class Solution {
public:
    bool isHappy(int n) {
        int current = generate(n);
        set<int> numbers;
        numbers.insert(n);

        while (current != 1)
        {

        	// find() return a pointer not a bool
        	if (numbers.find(current) != numbers.end()) return false;
        	else
        	{
        		numbers.insert(current);
        		current = generate(current);
        	}
        }

        return true;
    }

    int generate(int n) {
        int result = 0;
        while (n != 0)
        {
        	result += pow(n % 10, 2);
        	n /= 10;
        }

        return result;
    }
};