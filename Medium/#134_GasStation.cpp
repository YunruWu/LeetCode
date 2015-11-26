/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */


// O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalDiff = 0, curDiffSum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalDiff += gas[i] - cost[i];  // difference的总和
            if (curDiffSum < 0) {  //发现油箱空了，从下一个站点尝试
                curDiffSum = gas[i] - cost[i];
                start = i;
            }
            else
                curDiffSum += gas[i] - cost[i];
        }
        
        if (totalDiff < 0) return -1; // Total 能否 >= 0，就是是否存在这样的站点的 充分必要条件
        return start;
    }
};