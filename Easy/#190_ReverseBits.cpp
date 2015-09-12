/*
O(n)
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++)
        	// 位运算符加括号，判断n右移i位后是否为1，否则都为0
        	result = (result<<1) + (n>>i &1);

        return result;
    }
};