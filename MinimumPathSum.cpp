// Q) Minimum Path Sum -> https://leetcode.com/problems/minimum-path-sum/description/

    // Ans) 

    // i) Top-down approach : 

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> memo(m,vector<int> (n,-1));
    //     return solve(0,0,m,n,grid,memo);
    // }

    // int solve(int x,int y,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& memo){
    //     if(x==m-1 && y==n-1){
    //         return grid[x][y];
    //     }
    //     if(memo[x][y] == -1){
    //         int down = 1e3,right = 1e3;
    //         if(x < m-1) down = solve(x+1,y,m,n,grid,memo);
    //         if(y < n-1) right = solve(x,y+1,m,n,grid,memo);
    //         memo[x][y] = grid[x][y] + min(down,right);
    //     }
    //     return memo[x][y];
    // }

    // ii) Bottom-Up approach : 

    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> tab(m,vector<int> (n));
        tab[m-1][n-1] = grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int down  = (i < m-1) ? tab[i+1][j] : 1e3;
                int right = (j < n-1) ? tab[i][j+1] : 1e3;
                tab[i][j] = grid[i][j] + min(down,right);
            }
        }
        return tab[0][0];
    }