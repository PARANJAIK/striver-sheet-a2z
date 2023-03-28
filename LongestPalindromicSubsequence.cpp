// Q) Longest Palindromic subsequence -> https://leetcode.com/problems/longest-palindromic-subsequence/

    // Ans) 

    // i) My approach : (ACTUALLY CORRECT BUT TAKES LOT LONGER TIME THAN STRIVERS APPROACH , DONT KNOW WHY).

    // int longestPalindromeSubseq(string s) {
    //     int n = s.size();
    //     unordered_map<char,vector<int>> mapp;
    //     vector<vector<int>> memo(n+1,vector<int> (n,-1));
    //     for(int i=n-1;i>=0;i--){
    //         mapp[s[i]].push_back(i);
    //     }
    //     return solve(0,n-1,s,n,memo,mapp);
    // }

    // int solve(int i,int j,string& s,int n,vector<vector<int>>& memo,unordered_map<char,vector<int>>& mapp){
    //     if(i > j){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         // noconsider case
    //         int noconsider = solve(i+1,j,s,n,memo,mapp);
    //         // consider case
    //         int consider = 0;
    //         for(auto x : mapp[s[i]]){
    //             if(x <= j){
    //                 if(x == i){
    //                     consider = 1 + solve(i+1,x-1,s,n,memo,mapp);
    //                 }
    //                 else{
    //                     consider = 2 + solve(i+1,x-1,s,n,memo,mapp);
    //                 }
    //                 break;
    //             }
    //         }
    //         memo[i][j] = max(noconsider,consider);
    //     }
    //     return memo[i][j];
    // }

    // ii) Striver's approach :

    // int longestPalindromeSubseq(string s){
    //     string t = s;
    //     reverse(s.begin(),s.end());
    //     return longestCommonSubsequence(t,s);
    // }

    // int longestCommonSubsequence(string s,string t){
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n,vector<int> (m,-1));
    //     return f(n-1,m-1,s,t,dp);
    // }

    // int f(int i,int j,string &s,string &t,vector<vector<int>>& dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    //     return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    // }

    // iii) My 2nd approach - (TOP-DOWN APPROACH) :

    // int longestPalindromeSubseq(string s){
    //     int n = s.size();
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(0,n-1,s,memo);
    // }

    // int solve(int i,int j,string& s,vector<vector<int>>& memo){
    //     if(i >= j){
    //         if(i > j) return 0;
    //         return 1;
    //     }
    //     if(memo[i][j] == -1){
    //         int one = solve(i,j-1,s,memo);
    //         int two = solve(i+1,j,s,memo);
    //         int ans = max(one,two);
    //         if(s[i] == s[j]){
    //             int x = solve(i+1,j-1,s,memo);
    //             ans = max(ans,x+2);
    //         }
    //         memo[i][j] = ans;
    //     }
    //     return memo[i][j];
    // }

    // iv) My 2nd approach - (BOTTOM-UP APPROACH) :

    int longestPalindromeSubseq(string s){
        int n = s.size();
        vector<int> next(n+1),cur(n+1);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n+1;j++){
                if(i > j) cur[j] = 0;
                else if(i == j) cur[j] = 1;
                else{
                   cur[j] = max(cur[j-1],next[j]);
                   if(s[i] == s[j]) cur[j] = max(cur[j],next[j-1] + 2);
                }
            }
            next = cur;
        }
        return next[n-1];
    }
