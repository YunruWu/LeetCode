/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */


// quick sort
/*
Note that since we only need to consider one half of the array, the time complexity is O(n). 
If we need to consider both the two halves of the array, like quicksort, 
then the recursion will be T(n) = 2T(n/2) + O(n) and the complexity will be O(nlogn).

Of course, O(n) is the average time complexity. 
In the worst case, the recursion may become T(n) = T(n - 1) + O(n) and the complexity will be O(n^2).
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos < k - 1) left = pos + 1;
            else right = pos - 1;
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = left;
        int l = left + 1;
        while (l <= right) {
            if (nums[l] < nums[pivot]) {
                swap(nums[l], nums[right]);
                right--;
            }
            else
                l++;
        }
        swap(nums[pivot], nums[right]);
        return right;
    }
};


// (O(nlogn)) by simply sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


// O(n) space, O(n) time by priority queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};


// maxheap sorting O(klogn)
/*
1. Build a max-heap for nums, set heap_size to be nums.size();
2. Swap nums[0] (after buding the max-heap, it will be the largest element) with nums[heap_size - 1] (currently the last element). 
   Then decrease heap_size by 1 and max-heapify nums (recovering its max-heap property) at index 0;
3. Repeat 2 for k times and the k-th largest element will be stored finally at nums[heap_size].
 */
class Solution {
public:   
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
}