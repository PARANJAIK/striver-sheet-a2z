// Q) Edit Distance -> https://leetcode.com/problems/edit-distance/description/

    // Ans) 

    // i) My Top-down approach : 

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> memo(n,vector<int> (m,-1));
    //     return solve(0,0,word1,word2,memo);
    // }

    // int solve(int i,int j,string& word1,string& word2,vector<vector<int>>& memo){
    //     int n = word1.size();
    //     int m = word2.size();
    //     if(i==n && j==m){
    //         return 0;
    //     }
    //     else if(i==n){
    //         return (m-j);
    //     }
    //     else if(j==m){
    //         return (n-i);
    //     }
    //     if(memo[i][j] == -1){
    //         if(word1[i] == word2[j]){
    //             memo[i][j] = solve(i+1,j+1,word1,word2,memo);
    //         }
    //         else{
    //             memo[i][j] = min(solve(i+1,j,word1,word2,memo),solve(i+1,j+1,word1,word2,memo));
    //             memo[i][j] = min(memo[i][j],solve(i,j+1,word1,word2,memo));
    //             memo[i][j] = memo[i][j] + 1;
    //         }
    //     }
    //     return memo[i][j];
    // }

    // ii) Bottom-Up approach : 

    // int minDistance(string word1,string word2){
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> tab(n+1,vector<int> (m+1));
    //     tab[n][m] = 0;
    //     for(int i=0;i<n;i++){
    //        tab[i][m] = n-i;
    //     }
    //     for(int j=0;j<m;j++){
    //         tab[n][j] = m - j;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=m-1;j>=0;j--){
    //             if(word1[i] == word2[j]){
    //                 tab[i][j] = tab[i+1][j+1];
    //             }
    //             else{
    //                 tab[i][j] = min(tab[i+1][j],tab[i+1][j+1]);
    //                 tab[i][j] = min(tab[i][j],tab[i][j+1]);
    //                 tab[i][j] += 1;
    //             }
    //         }
    //     }
    //     return tab[0][0];
    // }