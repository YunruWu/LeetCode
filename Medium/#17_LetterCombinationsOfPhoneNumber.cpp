class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) return {};
        
        // handle initial case
        result.push_back("");
        string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (int i = 0; i < digits.length(); i++) {
        	vector<string> temp;
        	string letter = letters[digits[i] - '0'];
        	for (int j = 0; j < letter.length(); j++) {
        		for (int k = 0; k < result.size(); k++) {
        			temp.push_back(result[k] + letter[j]);
        		}
        	}

        	result = temp;
        }

        return result;
    }
};