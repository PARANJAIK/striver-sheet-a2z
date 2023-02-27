// Q) Buy and sell a stock -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

    // Ans) 

    // i) My approach : Just iterate over the prices array and maintain the min till that point and the difference of current price and the minimum till now is the current profit, if the current profit is greater than the maximum profit means ans variable, then ans is updated.

    int maxProfit(vector<int>& prices) {
        int minTillNow = INT_MAX;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            int currprofit = prices[i] - minTillNow;
            if(currprofit > ans) ans = currprofit;
            if(prices[i] < minTillNow) minTillNow = prices[i];
        }
        return ans;
    }