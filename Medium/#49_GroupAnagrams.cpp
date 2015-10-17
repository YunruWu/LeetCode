/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        std::sort(strs.begin(), strs.end());

        unordered_map<string, vector<string>> sv;

        for (int i = 0; i < strs.size(); i++) {
        	string current = strs[i];
        	std::sort(current.begin(), current.end());
        	
        	sv[current].push_back(strs[i]);
        }

        for (std::unordered_map<string, vector<string>>::iterator it = sv.begin(); it != sv.end(); it++) {
        	result.push_back(it->second);
        }

        return result;
    }
};