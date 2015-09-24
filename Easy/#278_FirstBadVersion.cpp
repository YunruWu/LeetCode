// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*
O(logn)
 */
class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 0, higher = n, mid = 0;
        while (lower < higher) {
        	// (lower + higher) / 2 may cause overflow, (lower + higher) > INT_MAX
        	mid = lower + (higher - lower) / 2;
        	if (isBadVersion(mid)) {
        		higher = mid;
        	}
        	else {
        		lower = mid + 1;
        	}
        }

        return lower; // always has a bad version
    }
};