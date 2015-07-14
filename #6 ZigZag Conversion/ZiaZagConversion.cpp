class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int step = numRows * 2 - 2;
        int len = s.length();

        // handle special cases
        if(numRows <= 1 || len <= numRows)
        	return s;

        // first row
        for (int i = 0; i < len; i += step)
        	result += s[i];

        // middle rows
        for (int j = 1; j < numRows-1; j++){
        	int k = 1;
        	for (int i = j; i < len; i += step){
        		result += s[i];
        		if ((k*step - j) < len)
        			result += s[k*step - j];
        		k += 1;
        	}
        }

        // last row
        for (int i = numRows - 1; i < len; i += step)
        	result += s[i];

        return result;
    }
};