/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
 */


/*
按位运算，所有数字自然要按二进制形式表达。一组数字按位与时，只有所有数字这一位上都为1时，结果才会为1。如果m=n,那自然结果就是m.下面讨论m!=n的情况。

让我们从最低位开始。
如果这一组数字的最低位不相同的话，那这一位就肯定会被消掉，变成0.如果m!=n,那最低位肯定是要被消掉的，因为最低位肯定会是一个0，一个1.这时，我们可以将m和n都右移一位，将最后一位忽略。

此时，又有了新的一组m和n。如果此时m=n,那结果就是m了。如果不是的话，那可以继续上一段的过程，将m和n右移一位。

重复上述操作，直到m=n。这个时候，从低位往高位所有进行与操作后结果为0的位数都已经被消掉，而高位的数字进行与操作不会发生变化，此时的m或者n再向左移动之前移动的位数，得到的就是这一组数字按位与后的结果。
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        
        while (m != n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        
        return m << shift;
    }
};