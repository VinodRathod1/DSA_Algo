class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empties = numBottles;
        
        while (empties >= numExchange) {
            int newBottles = empties / numExchange;
            ans += newBottles;
            empties = newBottles + (empties % numExchange);
        }
        
        return ans;
    }
};
