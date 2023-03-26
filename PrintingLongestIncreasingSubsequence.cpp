//   Q) Printing Longest Increasing Subsequences -> https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

    // Ans)
    
    // i) Backtracking from the dp table of O(n*n) time and O(n*n) space approach :
  
    // vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
    //     // Code here
    //      vector<vector<int>> tab(n+1,vector<int> (n+1,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=n;j>=0;j--){
    //             int ans = tab[i+1][j];
    //             if(j == 0 || nums[i] > nums[j-1]){
    //                 ans = max(ans,1 + tab[i+1][i+1]);
    //             }
    //             tab[i][j] = ans;
    //         }
    //     }
    //     vector<int> final;
    //     int i=0,j=0;
    //     while(i<n && j<=n){
    //         if(j==0 || nums[i] > nums[j-1]){
    //             if(1 + tab[i+1][i+1] >= tab[i+1][j]){      // actually there should not be equal to here if it really has to be lexicographically smaller.
    //                 final.push_back(nums[i]);
    //                 i = i+1;
    //                 j = i;
    //             }
    //             else{
    //                 i = i+1;
    //             }
    //         }
    //         else{
    //             i = i+1;
    //         }
    //     }
    //     return final;
    // }
    
    // ii) Backtracking from the dp table of O(n*n) time and O(n) space approach : 
    
            //   -> https://www.youtube.com/watch?v=IFfYfonAFGc
    
    vector<int> longestIncreasingSubsequence(int n,vector<int>& nums){
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi = 1;
        int lastindex = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }