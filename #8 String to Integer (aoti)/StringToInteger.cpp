class Solution
{
public:
	int myAtoi(string str)
	{
		int pos = 0;
		int result = 0;
		bool neg = false;
		while (str[pos] == ' ') pos++;
		if (str[pos] == '+')
		{
			pos++;
		}
		else if (str[pos] == '-')
		{
			pos++;
			neg = true;
		}
		while ((str[pos] >= '0') && (str[pos] <= '9'))
		{
			int digit = str[pos++] - '0';
			if ((result > 214748364) || ((result == 214748364) && (digit > 7)))
			{
				return neg ? -2147483648 : 2147483647;	// handle overflow
			}
			result *= 10;
			result += digit;
		}
		return neg ? (-result) : result;
	}
};