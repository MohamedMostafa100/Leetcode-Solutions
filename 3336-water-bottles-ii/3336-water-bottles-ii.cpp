class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int empty = numBottles;
        while(empty >= numExchange)
        {
            res++;
            empty -= numExchange - 1;
            numExchange++;
        }
        return res;
    }
};