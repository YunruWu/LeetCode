/*
Variable a tells you the number of ways to reach the current step, 
and b tells you the number of ways to reach the next step. 
So for the situation one step further up, the old b becomes the new a, 
and the new b is the old a+b, 
since that new step can be reached by climbing 1 step from what b represented 
or 2 steps from what a represented.

O(n)
 */

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (--n)	// not n--, at least execute the while loop once
        {
        	b += a;
        	a = b - a;
        }

        return b;
    }
};