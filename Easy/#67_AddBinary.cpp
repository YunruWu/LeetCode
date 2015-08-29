/*
O(n)
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length() - 1, blen = b.length() - 1;
        string result = "";
        int extra = 0;

        while (alen >= 0 || blen >= 0)
        {
        	int anum = 0, bnum = 0;
        	if (alen >= 0)
        	{
        		anum = a[alen] - '0';	// convert to int
        		alen--;
        	}
        	if (blen >= 0)
        	{
        		bnum = b[blen] - '0';
        		blen--;
        	}

        	// 相加后显示的结果是除以2的余数，进位是满2进1。从高位插入结果
        	// convert to char
        	result.insert(result.begin(), char((anum + bnum + extra) % 2 + '0'));	
        	extra = (anum + bnum + extra) / 2;	
        }

        // 最高位仍需进1
        if (extra == 1)
        	result.insert(result.begin(), '1');

        return result;
    }
};