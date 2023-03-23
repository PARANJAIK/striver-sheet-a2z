 // Q) Distinct Subsequences -> https://leetcode.com/problems/distinct-subsequences/description/

    // Ans) 

    // i) My approach : (WORKS)(TOP-DOWN)

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return 0;
        vector<vector<int>> memo(n,vector<int> (m,-1));
        return solve(0,0,n,m,s,t,memo);
    }

    int solve(int i,int j,int n,int m,string& s,string& t,vector<vector<int>>& memo){
        if(j == m){
            return 1;
        }
        if(i == n){
            return 0;
        }
        if(memo[i][j] == -1){
            if(s[i] == t[j]){
                memo[i][j] = solve(i+1,j+1,n,m,s,t,memo) + solve(i+1,j,n,m,s,t,memo);
            }
            else{
                memo[i][j] = solve(i+1,j,n,m,s,t,memo);
            }
        }
        return memo[i][j];
    }

    // ii) My approach WHICH FAILED(INITIAL ATTEMPT)

    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     unordered_map<char,vector<int>> mapp;
    //     for(int i=0;i<n;i++){
    //         mapp[s[i]].push_back(i);
    //     }
    //     vector<vector<int>> memo(n,vector<int> (m,-1));
    //     return solve(0,0,n,m,s,t,mapp,memo);
    // }

    // int solve(int i,int j,int n,int m,string& s,string& t,unordered_map<char,vector<int>>& mapp,vector<vector<int>>& memo){
    //     if(j == m){
    //         return 1;
    //     }
    //     if(i == n){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         int add = 0;
    //         for(auto x : mapp[t[j]]){
    //             if(x >= i){
    //                 add = add + solve(x+1,j+1,n,m,s,t,mapp,memo);
    //             }
    //         }
    //         memo[i][j] = add;
    //     }
    //     return memo[i][j];
    // }

    // iii) My approach (BOTTOM-UP)

    // int numDistinct(string s,string t){
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<double>> tab(n+1,vector<double>(m+1));
    //     if(m > n) return 0;
    //     for(int j=0;j<m+1;j++){
    //         tab[n][j] = 0;
    //     }
    //     for(int i=0;i<n+1;i++){
    //         tab[i][m] = 1;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=m-1;j>=0;j--){
    //             if(s[i] == t[j]) tab[i][j] = ((tab[i+1][j+1]) + (tab[i+1][j]));
    //             else tab[i][j] = tab[i+1][j];
    //         }
    //     }
    //     return tab[0][0];
    // }