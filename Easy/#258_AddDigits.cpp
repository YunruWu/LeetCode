/*
O(1)
 */
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};


/*
O(n)
 */
class Solution {
public:
    int addDigits(int n) {
        if (n >= 0 && n <= 9) {
            return n;
        }
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n = n/10;
        }

        addDigits(sum);
    }
};