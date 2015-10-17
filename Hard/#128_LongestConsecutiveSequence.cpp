/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
        	mp[nums[i]] = 1;
        }

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int maxlen = 1;  // update every when scanning
            if (mp.count(nums[i])) {
                mp[nums[i]] = 0;
        	    int left = nums[i] - 1;
        	    while (mp.count(left) && mp[left]) {  // count() takes linear time
        		    mp[left] = 0;
        		    left--;
        		    maxlen++;
        	    }

        	    int right = nums[i] + 1;
        	    while (mp.count(right) && mp[right]) {  
        		    mp[right] = 0;
        		    right++;
        		    maxlen++;
        	    }
            }
        	result = max(result, maxlen);
        }

        return result;
    }
};


// using unordered_set
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> record(nums.begin(),nums.end());
        int res = 1;
        for(int n : nums){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};