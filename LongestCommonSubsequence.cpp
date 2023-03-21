 // Q) Longest Common Subsequence -> https://leetcode.com/problems/longest-common-subsequence/description/

    // Ans) 

    // iii) Striver's approach (BOTTOM-UP) 

    // (BEST USE FOR TEMPLATE AND TO FIND LCS FROM DP ARRAY)

    int longestCommonSubsequence(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> tab(n+1,vector<int> (m+1));
        for(int i=0;i<n+1;i++){
            tab[i][m] = 0;
        }
        for(int j=0;j<m+1;j++){
            tab[n][j] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i] == t[j]) tab[i][j] = 1 + tab[i+1][j+1];
                else tab[i][j] = max(tab[i+1][j],tab[i][j+1]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<tab[i][j]<<" ";    // TO PRINT THE DP TABULATION ARRAY
        //     }
        //     cout<<endl;
        // }
        return tab[0][0];
    }



    // i) My approach (TOP-DOWN)(RUNS slightly better than striver's approach)(BUT striver has lesser code):

    // int longestCommonSubsequence(string text1, string text2) {
    //     if(text2.size() < text1.size()){
    //         string temp = text1;
    //         text1 = text2;
    //         text2 = temp;
    //     }
    //     int n = text1.size();
    //     int m = text2.size();
    //     unordered_map<char,vector<int>> mapp;
    //     for(int i=0;i<m;i++){
    //         mapp[text2[i]].push_back(i);
    //     }
    //     vector<vector<int>> memo(n+1,vector<int> (m+1,-1));
    //     int ans = solve(0,0,text1,text2,n,m,mapp,memo);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             cout<<memo[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return ans;
    // }

    // int solve(int i,int j,string& text1,string& text2,int n,int m,unordered_map<char,vector<int>>& mapp,vector<vector<int>>& memo){
    //     if(i==n || j==m){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         if(text1[i] == text2[j]){
    //            memo[i][j] = 1 + solve(i+1,j+1,text1,text2,n,m,mapp,memo);    // This is because when text1[i] is equal to text2[j] , then there is no sense in finding the no consider case, because we want the longest common subsequence.
    //         }
    //         else{
    //            int maxx = INT_MIN;
    //            // no consider case
    //            maxx = max(maxx,solve(i+1,j,text1,text2,n,m,mapp,memo));
    //            // consider case
    //             for(auto x : mapp[text1[i]]){
    //                if(x>=j){
    //                   maxx = max(maxx,1 + solve(i+1,x+1,text1,text2,n,m,mapp,memo));
    //                   break;
    //                }
    //             }
    //             memo[i][j] = maxx;
    //         }
    //     }
    //     return memo[i][j];
    // }

    // ii) Striver's approach (TOP-DOWN): 

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

    // iv) My Bottom-Up approach : 
    
    // int longestCommonSubsequence(string text1,string text2){
    //     if(text2.size() < text1.size()){
    //         string temp = text1;
    //         text1 = text2;
    //         text2 = temp;
    //     }
    //     int n = text1.size();
    //     int m = text2.size();
    //     unordered_map<char,vector<int>> mapp;
    //     for(int i=0;i<m;i++){
    //         mapp[text2[i]].push_back(i);
    //     }
    //     vector<vector<int>> tab(n+1,vector<int> (m+1));
    //     for(int i=0;i<n+1;i++){
    //         tab[i][m] = 0;
    //     }
    //     for(int j=0;j<m+1;j++){
    //         tab[n][j] = 0;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=m-1;j>=0;j--){
    //             if(text1[i] == text2[j]) tab[i][j] = 1 + tab[i+1][j+1];
    //             else{
    //                 int maxx = INT_MIN;
    //                 maxx = tab[i+1][j];
    //                 for(auto x : mapp[text1[i]]){
    //                     if(x>=j){
    //                         maxx = max(maxx,1+tab[i+1][x+1]);
    //                         break;
    //                     }
    //                 }
    //                 tab[i][j] = maxx;
    //             }
    //         }
    //     }
    //     for(int i=0;i<n+1;i++){
    //         for(int j=0;j<m+1;j++){
    //             cout<<tab[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return tab[0][0];
    // }
