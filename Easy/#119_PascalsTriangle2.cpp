/*
O(n^2)
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = 1;

        for (int i = 1; i < rowIndex + 1; i++)
       {
       		result[i] = 1;
       		for (int j = i - 1; j > 0; j--) 
       			// 当我们需要改变数组的值时，如果从前往后遍历，有时会带来很多麻烦，
       			// 比如需要插入值，导致数组平移，或者新的值覆盖了旧有的值，
       			// 但旧有的值依然需要被使用。
       			// 这种情况下，有时仅仅改变一下数组的遍历方向，就会避免这些困难。
       			result[j] += result[j-1];
       }

       return result;

    }
};