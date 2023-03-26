// Q) Longest Increasing Subsequence -> https://leetcode.com/problems/longest-increasing-subsequence/

    // Ans)

    // i) O(n*n) time complexity solution : (TOP-DOWN APPROACH)

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> memo(n,vector<int> (n+1,-1));
    //     return solve(0,0,nums,memo);
    // }

    // int solve(int ind,int prevind,vector<int>& nums,vector<vector<int>>& memo){
    //     int n = nums.size();
    //     if(ind == n){
    //         return 0;
    //     }
    //     if(memo[ind][prevind] != -1){
    //         return memo[ind][prevind];
    //     }
    //     // no consider
    //     int ans = solve(ind+1,prevind,nums,memo);
    //     // consider
    //     if(prevind == 0 || nums[ind] > nums[prevind-1]){
    //         ans = max(ans,1 + solve(ind+1,ind+1,nums,memo));
    //     }
    //     return memo[ind][prevind] = ans;
    // }

    // ii) O(n*logn) time complexity solution : (BINARY SEARCH APPROACH)

    // NOTE : The final subsequence that is stored in the temp vector is not the actual longest strictly increasing subsequence, but it just gives the length same as that of LIS.

    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> temp;
        int len = 1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }


    // iii) O(n*n) time complexity solution : (BOTTOM-UP APPROACH)

    // int lengthOfLIS(vector<int>& nums){
    //     int n = nums.size();
    //     vector<vector<int>> tab(n+1,vector<int> (n+1,0));
    //     // for(int j=0;j<n+1;j++){
    //     //     tab[n][j] = 0;        // all are initialised to zero to avoid base cases.
    //     // }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=n;j>=0;j--){
    //             int ans = tab[i+1][j];
    //             if(j == 0 || nums[i] > nums[j-1]){
    //                 ans = max(ans,1 + tab[i+1][i+1]);
    //             }
    //             tab[i][j] = ans;
    //         }
    //     }
    //     return tab[0][0];
    // }