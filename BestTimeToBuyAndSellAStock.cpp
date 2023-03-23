// Q) Buy and sell a stock -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
                            //   ->https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stock-buy-and-sell-1587115621

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


    // ii) CODE FOR GFG VARIETY OF THIS PROBLEM:

    // vector<vector<int>> stockBuySell(vector<int> prices,int n){
    //     int i = 0;
    //     vector<vector<int>> ans;
    //     int initial = 0;
    //     while(i < n){
    //         while(i<n-1 && prices[i+1] >= prices[i]) i++;
    //         if(prices[i] - prices[initial] > 0){
    //             vector<int> temp = {initial,i};
    //             ans.push_back(temp);
    //         }
    //         i++;
    //         initial = i;
    //     }
    //     return ans;
    // }
