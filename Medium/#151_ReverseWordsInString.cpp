/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 */

/*
Inplace solution
O(n) time, O(1) space
 */
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
        	if (s[i] != ' ') {
        		if (cur != 0) {
        		    s[cur++] = ' ';  // add a space between words in reversed string
        		}
        		int end = i;
        		while (end < s.length() && s[end] != ' ') {
        			s[cur++] = s[end++];  // move the word forward
        		}
        		// should be "cur - (end-i)" because i could be far away
        		reverse(s.begin() + cur - (end-i), s.begin() + cur);
        		i = end;
        	}
        }
        
        s.erase(s.begin() + cur, s.end());  // remove all spaces left in the string
    }
};

// O(n) space solution
class Solution {
public:
    void reverseWords(string &s) {
        string result;
        int pos = 0;
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == ' '){
                if (i > pos )
                    result = s.substr(pos,i-pos)+ " " + result ;
                pos = i + 1;
            }
            else if (i == s.size()-1)
                result = s.substr(pos,s.size()-pos)+" "+result;
        }
        s = result.substr(0,result.size()-1) ;
    }
};