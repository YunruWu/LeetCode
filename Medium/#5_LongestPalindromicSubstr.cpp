/*
O(n^2) in both time and space
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int begin = 0, maxLen = 1;
        bool table[1000][1000] = {false};
        // 初始化左上－右下对角线为1
        for (int i = 0; i < n; i++) {
        	table[i][i] = true;
        }
        //找长度为2最小的回文子串
        for (int i = 0; i < n - 1; i++) {
        	if (s[i] == s[i+1]) {
        		table[i][i+1] = true;
        		begin = i; // suppose only one palindromic substring
        		maxLen = 2;
        	}
        }

        //找长度为3，4，5...的回文子串
        for (int len = 3; len <= n; len++) {
        	for (int i = 0; i < n-len+1; i++) {  // 从0到（n-len+1）遍历s
        		int j = i + len - 1;
        		// 检查是否中间都符合会文条件，利用已计算出的结果向外扩展
        		if (s[i] == s[j] && table[i+1][j-1]) {
        			table[i][j] = true;
        			begin = i;
        			maxLen = len;
        		}
        	}
        }

        return s.substr(begin, maxLen);
    }
};


// Manacher's Alg
// O(n)
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
