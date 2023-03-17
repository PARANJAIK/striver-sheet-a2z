//    Q) Triangle Minimum Path Sum -> https://leetcode.com/problems/triangle/description/

    // Ans)

    // i) Top-down approach : 

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> memo(m,vector<int> (triangle[m-1].size(),-1));
        // vector<vector<int>> memo(m);
        // for(int i=0;i<m;i++){
        //     memo[i].assign(i+1,-1);
        // }
        return solve(0,0,m,triangle,memo);
    }

    int solve(int x,int y,int m,vector<vector<int>>& triangle,vector<vector<int>>& memo){
        if(x==m-1){
            return triangle[x][y];
        }
        if(memo[x][y]==-1){
            int same = solve(x+1,y,m,triangle,memo);
            int ahead = solve(x+1,y+1,m,triangle,memo);
            memo[x][y] = triangle[x][y] + min(same,ahead);
        }
        return memo[x][y];
    }

    // ii) Bottom-Up approach : 

    // int minimumTotal(vector<vector<int>>& triangle){
    //     int m = triangle.size();
    //     vector<vector<int>> tab(m,vector<int> (triangle[m-1].size()));
    //     for(int j=0;j<m;j++){
    //         tab[m-1][j] = triangle[m-1][j];
    //     }
    //     for(int i=m-2;i>=0;i--){
    //         for(int j=0;j<i+1;j++){
    //             tab[i][j] = triangle[i][j] + min(tab[i+1][j] , tab[i+1][j+1]);
    //         }
    //     }
    //     return tab[0][0];
    // }