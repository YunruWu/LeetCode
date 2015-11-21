/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
 */

class Solution {
public:
    string getHint(string secret, string guess) {
        string result;
        int bulls = 0, cows = 0;
        
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] == guess[i]) {
                secret[i] = guess[i] = ' ';
                bulls++;
            }
        }
        
        for (int i = 0; i < guess.size(); i++) {
            for (int j = 0; j < secret.size(); j++) {
                if (guess[i] != ' ' && secret[j] == guess[i]) {
                    secret[j] = ' ';
                    cows++;
                    break;
                }
            }
        }
        
        result = to_string(bulls) + "A" + to_string(cows) + "B";
        return result;
    }
};


// O(n)
class Solution {
public:
    string getHint(string secret, string guess) {
        string result;
        int bulls = 0, cows = 0;
        vector<int> se(10, 0);
        vector<int> gu(10, 0);
        
        for (int i = 0; i < guess.size(); i++) {
            char s = secret[i], g = guess[i];
            if (s == g) {
                bulls++;
            }
            else {
                se[s-'0']++;
                gu[g-'0']++;
            }
        }
        
        for (int i = 0; i < se.size(); i++) {
            cows += min(se[i], gu[i]);
        }
        
        result = to_string(bulls) + "A" + to_string(cows) + "B";
        return result;
    }
};