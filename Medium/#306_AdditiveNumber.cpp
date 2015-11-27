/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
 */


class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() <= 2) return false;
        
        string s1, s2;
        long long num1, num2, sum;
        for (int i = 0; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                s1 = num.substr(0, i);
                s2 = num.substr(i, j - i);
                if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) continue;
                num1 = atoll(s1.c_str());
                num2 = atoll(s2.c_str());
                sum = num1 + num2;
                string sum_s = to_string(sum);
                string current = s1 + s2 + sum_s;
                while (current.size() < num.size()) {
                    num1 = num2;
                    num2 = sum;
                    sum = num1 + num2;
                    sum_s = to_string(sum);
                    current += sum_s;
                }
                if (current == num) return true;
            }
        }
        
        return false;
    }
};


/*
use a helper function to add two strings.

Choose first two number then recursively check.

Note that the length of first two number can't be larger then half of the initial string, 
so the two loops in the first function will end when i>num.size()/2 and j>(num.size()-i)/2, 
this will actually save a lot of time.
 */
class Solution {
public:
        bool isAdditiveNumber(string num) {
            for(int i=1; i<=num.size()/2; i++){
                for(int j=1; j<=(num.size()-i)/2; j++){
                    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
                }
            }
            return false;
        }
        bool check(string num1, string num2, string num){
            string sum=add(num1, num2);
            if(num==sum) return true;
            if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
            else return check(num2, num.substr(0,sum.size()), num.substr(sum.size()));
        } 
        string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
    };