/*
O(n*k)
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
		if (n == 1) return "1";

		string result = "1";
		string current;

		// start from the second sequence
		for (int i = 1; i < n; i++)
		{
			int j = 0;
			for (; j < result.length(); j++)
			{
				int count = 1;

				// handle overflow when traverse through the string
				while ((j+1 < result.length()) && result[j+1] == result[j])
				{
					count++;
					j++;
				}

				current += to_string(count) + result[j];
			}

			result = current;
			current = "";
		}

		return result;
    }
};