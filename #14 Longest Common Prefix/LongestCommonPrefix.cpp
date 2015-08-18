/*
O(n^2)
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		// empty vector
		if (strs.size() == 0)
			return "";
		string result;
		
		for (int len = 0; len < strs[0].length(); len++){
			for (int j = 1; j < strs.size(); j++){
				if (strs[0][len] != strs[j][len])
					return result;		// end comparing when not equal
			}
			result += strs[0][len];
		}
		
		return result;
	}
};