// Q) Unique Paths -> https://leetcode.com/problems/unique-paths/description/

    // Ans) 

    // i) Top-down approach : 

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> memo(m,vector<int> (n,-1));
    //     return solve(0,0,m,n,memo);
    // }

    // int solve(int x,int y,int m,int n,vector<vector<int>>& memo){
    //     if(x == m-1 && y == n-1){
    //         return 1;
    //     }
    //     if(memo[x][y] == -1){
    //     int down = 0;
    //     int right = 0;
    //     if(x<m-1) down = solve(x+1,y,m,n,memo);
    //     if(y<n-1) right = solve(x,y+1,m,n,memo);
    //     memo[x][y] = down+right;
    //     }
    //     return memo[x][y];
    // }

    // ii) Bottom-Up approach :

    // int uniquePaths(int m,int n){
    //     vector<vector<int>> tab(m,vector<int> (n));
    //     tab[m-1][n-1] = 1;
    //     for(int i=m-1;i>=0;i--){
    //         for(int j=n-1;j>=0;j--){
    //             if(i==m-1 && j==n-1) continue;
    //             int down = 0,right = 0;
    //             if(i < m-1) down = tab[i+1][j];
    //             if(j < n-1) right = tab[i][j+1];
    //             tab[i][j] = down + right;
    //         }
    //     }
    //     return tab[0][0];
    // }

    // iii) Combinatorics approach :(MOST OPTIMAL)

    int uniquePaths(int m,int n){
        int N = n+m-2;
        int r = m-1;
        double ans = 1;
        for(int i=1;i<=r;i++){
            ans = ans*(N-r+i)/i;
        }
        return (int)ans;
    }