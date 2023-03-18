// Q) Target Sum -> https://leetcode.com/problems/target-sum/description/

    // Ans) 

    // i) Bottom-Up approach :

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }
        if((totalsum + target)%2==1) return 0;
        int sum = (totalsum + target)/2;
        if(sum < 0){
            sum = (totalsum - sum);       // This is important becuase the sum of subset 1 may be negative, in that case we need to go for the sum of 2nd subset in order to do DP.
        }
        vector<vector<int>> tab(n+1,vector<int> (sum+1));
        for(int j=0;j<sum+1;j++){
            tab[n][j] = 0;
        }
        tab[n][0] = 1;
        // for(int i=0;i<n+1;i++){
        //     tab[i][0] = 1;         // This is not the case because, the array can contain 0 as elements.
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<sum+1;j++){
                if(nums[i] <= j) tab[i][j] = tab[i+1][j] + tab[i+1][j-nums[i]];
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][sum];
    }