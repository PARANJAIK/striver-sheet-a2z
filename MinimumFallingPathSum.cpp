// Q) Minimum Falling Path Sum -> https://leetcode.com/problems/minimum-falling-path-sum/

    // Ans) 

    // i) Top down Approach :

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int minn = INT_MAX;
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     for(int j=0;j<n;j++){
    //         minn = min(minn , solve(0,j,n,matrix,memo));
    //     }
    //     return minn;
    // }

    // int solve(int x,int y,int n,vector<vector<int>>& matrix,vector<vector<int>>& memo){
    //     if(x == n-1){
    //         return matrix[x][y];
    //     }
    //     if(memo[x][y] == -1){
    //         int behind = (y > 0) ? solve(x+1,y-1,n,matrix,memo) : 1e9;
    //         int same = solve(x+1,y,n,matrix,memo);
    //         int ahead = (y < n-1) ? solve(x+1,y+1,n,matrix,memo) : 1e9;
    //         int minn = min(behind,same);
    //         minn = min(minn,ahead);
    //         memo[x][y] = matrix[x][y] + minn;
    //     }
    //     return memo[x][y];
    // }

    // ii) Bottom-Up approach with Space optimization : 

    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size();
        // vector<vector<int>> tab(n,vector<int> (n));
        vector<int> next(n);
        for(int j=0;j<n;j++){
            next[j] = matrix[n-1][j];
        }
        int ans = INT_MAX;
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int behind = (j > 0) ? next[j-1] : 1e9;
                int same = next[j];
                int ahead = (j < n-1) ? next[j+1] : 1e9;
                int minn = min(behind,same);
                minn = min(minn,ahead);
                temp[j] = matrix[i][j] + minn;
                if(i==0){
                    ans = min(ans,temp[j]);
                }
            }
            next = temp;
        }
        if(n==1){
            for(int j=0;j<n;j++){
                ans = min(ans,next[j]);
            }
        }
        return ans;
    }