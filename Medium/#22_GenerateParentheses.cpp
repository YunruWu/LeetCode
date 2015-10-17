class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(vector<string>& result, string temp, int left, int right, int num) {
    	// end point of backtracking
    	if (temp.length() == num * 2) {
    		result.push_back(temp);
    		return;  // end of function
    	}

    	if (left < num ) {
    		backtrack(result, temp+"(", left+1, right, num); // left++ is wrong
    	}

    	if (right < left) {
    		backtrack(result, temp+")", left, right+1, num)
    	}
    }
};