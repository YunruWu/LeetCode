/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */

// using hash map
// O(n)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10) return result;
        string sequence;
        unordered_map<string, int> mp;

        for (int i = 0; i < s.size() - 9; i++) {
        	sequence = s.substr(i, 10);
        	if (mp.find(sequence) != mp.end()) {
        		mp[sequence]++;
        	}
        	else
        		mp[sequence]++;
        }
        
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            if (iter->second > 1) {
                result.push_back(iter->first);
            }
        }

        return result;
    }
};


// using bit manipulation
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}
