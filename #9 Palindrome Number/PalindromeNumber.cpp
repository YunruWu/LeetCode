class Solution {
public:
    bool isPalindrome(int x) {
		// handle negative numbers
		if (x < 0)
			return false;
		
		// count bits
		int count = 0;
		int y = x;
		while (y){
			count ++;
			y /= 10;
		}
		
		// reverse half of the number
		int temp = 0;
		for (int i=0; i < count/2; i++){
			temp = temp*10 + x%10;
			x /= 10;
		}
		if (count%2 == 1)
			x /= 10;
		
		return temp == x;
    }
};