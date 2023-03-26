// Q) Largest Divisible Subset -> https://leetcode.com/problems/largest-divisible-subset/

    // Ans)

    // i) Backtracking from the dp table of O(n*n) time and O(n) space approach: (SIMILAR TO LIS)

    vector<int> largestDivisibleSubset(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> index(n);
        int maxi = 0;
        int lastindex = 0;
        for(int i=0;i<n;i++){
            index[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    index[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(index[lastindex] != lastindex){
            lastindex = index[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    // ii) Backtracking from the dp table of O(n*n) time and O(n*n) space approach : (SIMILAR TO LIS) 

    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> tab(n+1,vector<int> (n+1,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=n;j>=0;j--){
    //             int ans = tab[i+1][j];
    //             if(j==0 || nums[j-1]%nums[i] == 0 || nums[i]%nums[j-1] == 0){
    //                 if(j == 0){
    //                     ans = max(ans,1 + tab[i+1][i+1]);
    //                 }
    //                 else if(nums[j-1]%nums[i] == 0){
    //                     ans = max(ans,1 + tab[i+1][j]);
    //                 }
    //                 else{
    //                     ans = max(ans,1 + tab[i+1][i+1]);
    //                 }
    //             }
    //             tab[i][j] = ans;
    //         }
    //     }
    //     vector<int> ans;
    //     int i=0,j=0;
    //     while(i<n && j<=n){
    //         if(j == 0 || nums[i]%nums[j-1] == 0){
    //             if(1 + tab[i+1][i+1] > tab[i+1][j]){
    //                 ans.push_back(nums[i]);
    //                 i = i+1;
    //                 j = i;
    //             }
    //             else{
    //                 i = i+1;
    //             }
    //         }
    //         else if(nums[j-1]%nums[i] == 0){
    //             ans.push_back(nums[i]);
    //             i = i + 1;
    //         }
    //         else{
    //             i = i + 1;
    //         }
    //     }
    //     return ans;
    // }