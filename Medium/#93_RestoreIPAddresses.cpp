/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        backtrack(s, 0, 0, ip, result);
        return result;
    }

    void backtrack(string s, int i, int part, string ip, vector<string>& result) {
    	int len = s.length();
    	if (i == len && part == 4) {
    		ip.erase(ip.end() - 1);
    		result.push_back(ip);
    		return;
    	}

    	if (len - i > 3 * (4-part)) return;
    	if (len - i < 4 - part) return;
    	int num = 0;
    	for (int j = i; j < i + 3; j++) {
    		num = num * 10 + (s[j] - '0');
    		if (num <= 255) {
    			ip += s[j];
    			backtrack(s, j+1, part+1, ip+'.', result);
    		}
    		if (num == 0) break;
    	}
    }
};