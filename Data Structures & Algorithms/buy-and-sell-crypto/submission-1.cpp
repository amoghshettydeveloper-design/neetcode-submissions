class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];
        for(int n: prices){
            minPrice = min(minPrice,n);
            profit = max(profit,n-minPrice);
        }
        return profit;
    }
};
