// Q) Best time to buy and sell stock II -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

    // Ans) 

    // i) My approach : 

    int maxProfit(vector<int>& prices) {
        int i = 0;
        int initial = 0;
        int n = prices.size();
        int ans = 0;
        while(i < n){
            while(i<n-1 && prices[i+1] >= prices[i]) i++;
            if(prices[i] - prices[initial] > 0){
                ans += prices[i] - prices[initial];
            }
            i++;
            initial = i;
        }
        return ans;
    }