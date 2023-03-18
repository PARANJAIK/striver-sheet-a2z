// Q) Partition Equal subset sum -> https://leetcode.com/problems/partition-equal-subset-sum/description/

    // Ans) 

    // i) Top-down approach : 

    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i=0;i<n;i++){
    //         sum += nums[i];
    //     }
    //     if(sum%2==1) return false;
    //     sum = sum/2;
    //     vector<vector<int>> memo(n+1,vector<int> (sum+1,-1));
    //     return solve(0,sum,n,nums,memo);
    // }

    // bool solve(int index,int sum,int n,vector<int>& nums,vector<vector<int>>& memo){
    //     if(index == n){
    //         if(sum == 0) return true;
    //         else return false;
    //     }
    //     if(sum == 0) return true;
    //     if(memo[index][sum] == -1){
    //         bool noconsider = solve(index+1,sum,n,nums,memo);
    //         bool consider = false;
    //         if(nums[index] <= sum) consider = solve(index+1,sum-nums[index],n,nums,memo);
    //         memo[index][sum] = noconsider || consider;
    //     }
    //     return memo[index][sum];
    // }

    // ii) Bottom-Up approach : 

    // bool canPartition(vector<int>& nums){
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i=0;i<n;i++){
    //         sum += nums[i];
    //     }
    //     if(sum%2==1) return false;
    //     sum = sum/2;
    //     vector<vector<int>> tab(n+1,vector<int> (sum+1));
    //     for(int j=0;j<sum+1;j++){
    //         tab[n][j] = false;
    //     }
    //     for(int i=0;i<n+1;i++){
    //         tab[i][0] = true;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=1;j<sum+1;j++){
    //             if(nums[i] <= j) tab[i][j] = (tab[i+1][j] || tab[i+1][j-nums[i]]);
    //             else tab[i][j] = tab[i+1][j];
    //         }
    //     }
    //     return tab[0][sum];
    // }