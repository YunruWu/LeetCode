/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.

 */

// Sorting solution
// O(nlogn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int n = citations.size();

        for (int i = 0; i < n; i++) {
        	if (citations[i] >= n - i) { // not "==" not "n-1-i"
        		//return citations[i]; 
        		return n - i; // if citations = [100]
        	}
        }

        return 0; // handle [0] else return 1
    }
};


// Hash Table solution
// The idea is to use another array, index is the citation 
// and value is the number of papers that has at least the citation. 
// Since the h-index can only be n, the new array will only need the index to be at most n, 
// thus the array size will only need n+1. 
// Papers that have more than n citations will store in array[n]. 
// Go through the array based on h index definition: array[i]>=i, find the max value of i.
// O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
    	if (citations.empty()) return 0;
        int n = citations.size();

        // 被引用的次数作为table的index，被引用相同次数的paper数目作为value
        vector<int> table(n+1, 0);
        for (int i = 0; i < n; i++) {
        	if (citations[i] >= n) {
        		table[n]++;
        	}
        	else {
        		table[citations[i]]++;
        	}
        }

        int paper = 0;
        for (int i = n; i >= 0; i--) {
        	paper += table[i];
        	if (paper >= i) {
        		return i;  // not "return paper;", return the citations 
        	}
        }
    }
};