class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, lo = prices[0];
        for(int i=0; i<prices.size(); i++) {
            lo = min(lo, prices[i]);
            profit = max(profit, prices[i] - lo);
        }
        return profit;
    }
};
