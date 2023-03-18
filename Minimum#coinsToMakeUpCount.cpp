// Q) Minimum number of coins to make up amount -> https://leetcode.com/problems/coin-change/description/
                                                //  -> https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=-minimum-number-of-coins4426

    // Ans) 

    // i) Top-down approach :

    int coinChange(vector<int>& coins,int amount){
        int n = coins.size();
        vector<vector<int>> memo(n+1,vector<int> (amount+1,-1));
        int ans = solve(0,amount,n,coins,memo);
        if(ans == 1e9) return -1;
        return ans;
    }

    int solve(int index,int amount,int n,vector<int>& coins,vector<vector<int>>& memo){
        if(amount == 0){
            return 0;
        }
        if(index == n){
            return 1e9;
        }
        if(memo[index][amount] == -1){
            int noconsider = solve(index+1,amount,n,coins,memo);
            int consider = 1e9;
            if(coins[index] <= amount) consider = 1 + solve(index,amount - coins[index],n,coins,memo);
            memo[index][amount] = min(noconsider,consider);
        }
        return memo[index][amount];
    }

    // ii) Bottom-up approach : 
    
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> tab(n+1,vector<int>(amount+1));
    //     for(int j=0;j<amount+1;j++){
    //         tab[n][j] = 1e9;
    //     }
    //     for(int i=0;i<n+1;i++){
    //         tab[i][0] = 0;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=1;j<amount+1;j++){
    //             if(coins[i] <= j) tab[i][j] = min(tab[i+1][j],1 + tab[i][j-coins[i]]);
    //             else tab[i][j] = tab[i+1][j];
    //         }
    //     }
    //     if(tab[0][amount] == 1e9) return -1;
    //     return tab[0][amount];
    // }