/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
        	int mid = left + (right - left) / 2;
        	if (target == nums[mid]) {
    			return mid;
        	}

        	// there exists rotation; the middle element is in the left part of the array
        	if (nums[mid] > nums[right]) {
        		if (target < nums[mid] && target >= nums[left]) {
        			right = mid - 1;
        		}
        		else
        			left = mid + 1;
        	}
        	// there exists rotation; the middle element is in the right part of the array
        	else if (nums[mid] < nums[left]) {
        		if (target > nums[mid] && target <= nums[right]) {
        			left = mid + 1;
        		}
        		else
        			right = mid - 1;
        	}
        	// no rotation
        	else {
        		if (target < nums[mid]) {
        			right = mid - 1;
        		}
        		else
        			left = mid + 1;
        	}
        }

        return -1;
    }
};


// find the index of the smallest value using binary search
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};