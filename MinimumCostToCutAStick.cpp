// Q) Minimum Cost to Cut a Stick -> https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

    // Ans) 

    // i) Striver's approach (TOP-DOWN):

    // int minCost(int n,vector<int>& cuts){
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(),0);
    //     sort(cuts.begin(),cuts.end());
    //     int size = cuts.size();
    //     vector<vector<int>> memo(size,vector<int> (size,-1));
    //     return solve(1,size-2,cuts,memo);
    // }

    // int solve(int i,int j,vector<int>& cuts,vector<vector<int>>& memo){
    //     if(i > j){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         int ans = INT_MAX;
    //         for(int k=i;k<=j;k++){
    //             ans = min(ans,cuts[j+1] - cuts[i-1] + solve(i,k-1,cuts,memo) + solve(k+1,j,cuts,memo));
    //         }
    //         memo[i][j] = ans;
    //     }
    //     return memo[i][j];
    // }

    // ii) striver's approach (BOTTOM-UP):

    int minCost(int n,vector<int>& cuts){
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int size = cuts.size();
        vector<vector<int>> tab(size,vector<int> (size,0));
        for(int i=size-2;i>=1;i--){
            for(int j=1;j<=size-2;j++){
                if(i > j) continue;
                int ans = INT_MAX;
                for(int k=i;k<=j;k++){
                    ans = min(ans,cuts[j+1] - cuts[i-1] + tab[i][k-1] + tab[k+1][j]);
                }
                tab[i][j] = ans;
            }
        }
        return tab[1][size-2];
    }

    // iii) My initial approach : (TLE BECAUSE OF n*n space used);

    // int minCost(int n, vector<int>& cuts) {
    //     vector<vector<int>> memo(n+1,vector<int> (n+1,-1));
    //     return solve(0,n,cuts,memo);
    // }

    // int solve(int i,int j,vector<int>& cuts,vector<vector<int>>& memo){
    //     if(j - i < 2){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         int ans = INT_MAX;
    //         for(auto cut : cuts){
    //             if(i<cut && cut<j){
    //                 int temp = (j-i) + solve(i,cut,cuts,memo) + solve(cut,j,cuts,memo);
    //                 ans = min(ans,temp);
    //             }
    //         }
    //         if(ans == INT_MAX) memo[i][j] = 0;
    //         else memo[i][j] = ans;
    //     }
    //     return memo[i][j];
    // }