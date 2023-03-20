// Q) Longest common Substring -> https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-common-substring1452

    // Ans) 
    
    // i) Top-down approach : 
    
    // int longestCommonSubstr (string s1, string s2, int n, int m)
    // {
    //     // your code here
    //     unordered_map<char,vector<int>> mapp;
    //     vector<vector<int>> memo(n,vector<int> (m,-1));
    //     for(int i=0;i<m;i++){
    //         mapp[s2[i]].push_back(i);
    //     }
    //     int ans = 0;
    //     for(int i=0;i<n;i++){
    //         for(auto j : mapp[s1[i]]){
    //             // int ptr1 = i,ptr2 = j;
    //             // int length = 0;
    //             // while(ptr1<n && ptr2 < m && s1[ptr1]==s2[ptr2]){        // JUST USED DP TO DO THIS PART OF CODE, BECAUSE HERE CERTAIN SUBPROBLEMS ARE BEING REPEATED IF YOU CAN OBSERVE.
    //             //     ptr1++;
    //             //     ptr2++;
    //             //     length++;
    //             // }
    //             // ans = max(ans,length);
    //             int length = solve(i,j,s1,s2,n,m,memo);
    //             ans = max(ans,length);
    //         }
    //     }
    //     return ans;
    // }
    
    // int solve(int i,int j,string& s1,string& s2,int n,int m,vector<vector<int>>& memo){
    //     if(i==n || j==m){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         if(s1[i] != s2[j]){
    //             memo[i][j] =  0;
    //         }
    //         else{
    //             memo[i][j] = 1 + solve(i+1,j+1,s1,s2,n,m,memo);
    //         }
    //     }
    //     return memo[i][j];
    // }
    
    // ii) Bottom-Up approach : 
    
    int longestCommonSubstr(string s1,string s2,int n,int m){
        // unordered_map<char,vector<int>> mapp;
        vector<vector<int>> tab(n+1,vector<int> (m+1));
        // for(int i=0;i<m;i++){
        //     mapp[s2[i]].push_back(i);       // Use of map is unnecessary in this question
        // }
        int ans = 0;
        for(int j=0;j<m+1;j++){
            tab[n][j] = 0;
        }
        for(int i=0;i<n+1;i++){
            tab[i][m] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i] != s2[j]) tab[i][j] = 0;
                else tab[i][j] = 1 + tab[i+1][j+1];
                ans = max(ans,tab[i][j]);
            }
        }
        return ans;
    }