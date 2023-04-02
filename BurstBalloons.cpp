// Q) Burst Balloons -> https://leetcode.com/problems/burst-balloons/description/
                        // -> https://www.youtube.com/watch?v=Yz4LlDSlkns
    // Ans) 

    // i) Stiver's approach : (TOP-DOWN APPRAOCH)

    // NOTE: The IMP point is in this problem we do which is the last balloon we will burst, and then do two sub problems, the left part and the right part. Because these are independent of each other if we consider the last balloon case.

    // int maxCoins(vector<int>& nums){
    //     nums.push_back(1);
    //     nums.insert(nums.begin(),1);
    //     int n = nums.size();
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(1,n-2,nums,memo);
    // }

    // int solve(int i,int j,vector<int>& nums,vector<vector<int>>& memo){
    //     if(i>j) return 0;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     int temp = INT_MIN;
    //     for(int k=i;k<=j;k++){
    //         temp = max(temp,nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums,memo) + solve(k+1,j,nums,memo));
    //     }
    //     return memo[i][j] = temp;
    // }

    // ii) (BOTTOM-UP APPROACH)

    int maxCoins(vector<int>& nums){
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        vector<vector<int>> tab(n,vector<int> (n,0));
        for(int i=n-2;i>=1;i--){
            for(int j=1;j<=n-2;j++){
                if(i > j) tab[i][j] = 0;
                else{
                    int temp = INT_MIN;
                    for(int k=i;k<=j;k++){
                        temp = max(temp,nums[i-1]*nums[k]*nums[j+1] + tab[i][k-1] + tab[k+1][j]);
                    }
                    tab[i][j] = temp;
                }
            }
        }
        return tab[1][n-2];
    }

    // iii) My initial approach (FAILS):

    // NOTE :  This fails because i used the first balloon to be burst approach, and here the left and right parts are dependent on each other.

    // int maxCoins(vector<int>& nums) {
    //     nums.push_back(1);
    //     nums.insert(nums.begin(),1);
    //     int n = nums.size();
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(1,n-2,nums,memo);
    // }

    // int solve(int i,int j,vector<int> & nums,vector<vector<int>>& memo){
    //     if(i > j){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         int temp = INT_MIN;
    //         for(int k=i;k<=j;k++){
    //             int a = nums[k];
    //             int x = nums[k-1]*nums[k]*nums[k+1];
    //             nums[k] = nums[k+1];
    //             int y = solve(i,k-1,nums,memo);
    //             nums[k] = nums[k-1];
    //             int z = solve(k+1,j,nums,memo);
    //             nums[k] = a;
    //             temp = max(temp,x+y+z);
    //         }
    //         memo[i][j] = temp;
    //     }
    //     return memo[i][j];
    // }