class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int size = prices.size();
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        return profit;
    }
};
