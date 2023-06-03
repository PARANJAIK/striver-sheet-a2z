// Q) Kth Manhattan Distance Neighbourhood -> https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

// Ans) 

// i) Proper approach : 

vector<vector<int> > Solution::solve(int K, vector<vector<int> > &mat){
    int n = mat.size();
    int m = mat[0].size();
    pair<int,int> p[4] = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (K+1,0)));
    for(int k=0;k<=K;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(k == 0){
                    dp[i][j][k] = mat[i][j];
                    continue;
                }
                dp[i][j][k] = dp[i][j][k-1];
                for(int v=0;v<4;v++){
                    int x = i + p[v].first;
                    int y = j + p[v].second;
                    if(0<=x && x<n && 0<=y && y<m){
                        dp[i][j][k] = max(dp[i][j][k],dp[x][y][k-1]);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = dp[i][j][K];
        }
    }
    return ans;
}
