// Q) Tiling With Dominoes -> https://www.interviewbit.com/problems/tiling-with-dominoes/

// Ans) 

// i) Proper approach : https://www.youtube.com/watch?v=yn2jnmlepY8   -> WilliamFiSet

#define int long long int
int M = 1e9+7;

int32_t Solution::solve(int32_t a){
    vector<vector<int>> dp(a+1,vector<int> (8,0));
    dp[0][7] = 1;
    for(int i=1;i<a+1;i++){
        dp[i][0] += dp[i-1][7]%M;
        dp[i][1] += dp[i-1][6]%M;
        dp[i][3] += dp[i-1][7]%M + dp[i-1][4]%M;
        dp[i][4] += dp[i-1][3]%M;
        dp[i][6] += dp[i-1][7]%M + dp[i-1][1]%M;
        dp[i][7] += dp[i-1][3]%M + dp[i-1][6]%M + dp[i-1][0]%M;
    }
    return (dp[a][7])%M;
}

// const int M = 1e9 + 7;

// int mysolve(int ind,int a,vector<vector<int>>& grid,vector<int>& memo){
//     if(ind >= 3*a){
//         return 0;
//     }
//     if(memo[ind] != -1) return memo[ind];
//     if(grid[ind/a][ind%a] == 1) return mysolve(ind+1,a,grid,memo);
//     int x = ind/a;
//     int y = ind%a;
//     // checking for possibility of vertical domino
//     int ans1 = 0;
//     int ans2 = 0;
//     if(grid[x][y] == 0 && x+1<3 && grid[x+1][y] == 0){
//         grid[x][y] = 1;
//         grid[x+1][y] = 1;
//         ans1 = mysolve(ind+1,a,grid,memo);
//         grid[x][y] = 0;
//         grid[x+1][y] = 0;
//     }
//     // checking for possibility of horizontal domino
//     if(grid[x][y] == 0 && y+1 < a && grid[x][y+1] == 0){
//         grid[x][y] = 1;
//         grid[x][y+1] = 1;
//         ans2 = mysolve(ind+2,a,grid,memo);
//         grid[x][y] = 0;
//         grid[x][y+1] = 0;
//     }
//     return memo[ind] = (ans1 + ans2)%M;
// }

// int Solution::solve(int a) {
//     if(a%2 == 1) return 0;
//     vector<vector<int>> grid(3,vector<int> (a,0));
//     vector<int> memo(a*3 + 1,-1);
//     return mysolve(0,a,grid,memo);
// }
