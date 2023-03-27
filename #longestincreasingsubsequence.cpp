// Q) Number of longest increasing subsequence -> https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

    // Ans) 

    // i) O(n*n) time and O(n) space dp table approach : 

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && 1 + dp[j] >= dp[i]){
                    if(1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(1 + dp[j] == dp[i]) cnt[i] += cnt[j];
                }
            }
            if(dp[i] == maxi) ans+=cnt[i];
            else if(dp[i] > maxi){
                maxi = dp[i];
                ans = cnt[i];
            }
        }
        return ans;
    }