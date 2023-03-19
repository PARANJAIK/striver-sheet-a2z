// Q) # combinations of coins to make up the amount -> https://leetcode.com/problems/coin-change-ii/description/

    // Ans) 

    // i) Top-down approach : 

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n+1,vector<int>(amount+1,-1));
        return solve(0,n,amount,coins,memo);
    }

    int solve(int index,int n,int amount,vector<int>& coins,vector<vector<int>>& memo){
        if(amount == 0){
            return 1;
        }
        if(index == n){
            return 0;
        }
        if(memo[index][amount] == -1){
            if(coins[index] <= amount) memo[index][amount] = solve(index+1,n,amount,coins,memo) + solve(index,n,amount-coins[index],coins,memo);
            else memo[index][amount] = solve(index+1,n,amount,coins,memo);
        }
        return memo[index][amount];
    }