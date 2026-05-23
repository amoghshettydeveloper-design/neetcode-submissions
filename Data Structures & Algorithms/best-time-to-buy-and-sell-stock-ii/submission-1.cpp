class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> resArr;
        int min = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>min){
                profit += (prices[i]-min);
                min = prices[i];
            }
            min = prices[i];
        }
        return profit;
    }
};