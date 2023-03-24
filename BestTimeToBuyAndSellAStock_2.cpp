// Q) Best time to buy and sell stock II -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

    // Ans) 

    // i) My approach : 

    // int maxProfit(vector<int>& prices) {
    //     int i = 0;
    //     int initial = 0;
    //     int n = prices.size();
    //     int ans = 0;
    //     while(i < n){
    //         while(i<n-1 && prices[i+1] >= prices[i]) i++;
    //         if(prices[i] - prices[initial] > 0){
    //             ans += prices[i] - prices[initial];
    //         }
    //         i++;
    //         initial = i;
    //     }
    //     return ans;
    // }

    // ii) Recursive Top-down approach : 

    // int maxProfit(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<int>> memo(n,vector<int> (2,-1));
    //     return solve(0,1,prices,memo);
    // }

    // int solve(int i,int buy,vector<int>& prices,vector<vector<int>>& memo){
    //     int n = prices.size();
    //     if(i == n){
    //         return 0;
    //     }
    //     if(memo[i][buy] == -1){
    //        if(buy){
    //            memo[i][buy] = max(-prices[i]+solve(i+1,0,prices,memo),solve(i+1,1,prices,memo));
    //        }
    //        else{
    //           memo[i][buy] = max(prices[i] + solve(i+1,1,prices,memo),solve(i+1,0,prices,memo));
    //        }
    //     }
    //     return memo[i][buy];
    // }

    // iii) Recursive Bottom-up and space optimized approach : 

    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<int> next(2);
        next[0] = 0;
        next[1] = 0;
        for(int i=n-1;i>=0;i--){
            vector<int> cur(2);
            cur[0] = max(prices[i] + next[1],next[0]);
            cur[1] = max(-prices[i] + next[0],next[1]);
            next = cur;
        }
        return next[1];
    }
