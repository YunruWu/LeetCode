/*
O(n)
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.length();
        unordered_map<char, char> map;
        for (int i = 0; i < slen; i++)
        {
        	if (map.find(s[i]) != map.end() && map[s[i]] != t[i]) return false;
        	else map[s[i]] = t[i];
        }

        // also need to map t to s
        map.clear();
        for (int i = 0; i < slen; i++)
        {
        	if (map.find(t[i]) != map.end() && map[t[i]] != s[i]) return false;
        	else map[t[i]] = s[i];
        }

        return true;
    }
};