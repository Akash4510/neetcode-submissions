class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;

        int maxProfit = 0;

        int left = 0;
        int right = 1;
    
        for (right; right < n; right++) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                maxProfit = max(prices[right] - prices[left], maxProfit);
            }
        }

        return maxProfit < 0 ? 0 : maxProfit;
    }
};
