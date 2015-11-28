/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        if (nums.empty()) return result;
        
        // convert to array of string
        vector<string> s;
        for (int num: nums) {
            s.push_back(to_string(num));
        }
        
        // sort
        std::sort(s.begin(), s.end(), compare);
        
        // combine strings together
        for (int i = 0; i < s.size(); i++) {
            result += s[i];
        }
        
        // erase leading 0s
        while (result[0] == '0' && result.size() > 1) {
            result.erase(0, 1);
        }
        
        return result;
    }
    
    static bool compare(string s1, string s2) {
        return (s1 + s2) > (s2 + s1);
    }
};