// Q) Ninja's Training -> https://practice.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

    // Ans) 
    
    // i) Top-down approach : 
  
    // int maximumPoints(vector<vector<int>>& points, int n) {
    //     // Code here
    //     vector<vector<int>> memo(n, vector<int> (3,-1));
    //     return solve(0,-1,points,n,memo);
    // }
    
    // int solve(int days,int prevact,vector<vector<int>>& points,int n,vector<vector<int>>& memo){
    //     if(days == n){
    //         return 0;
    //     }
    //     if(days == 0){
    //         int maxx = INT_MIN;
    //         for(int i=0;i<3;i++){
    //             maxx = max(maxx,points[days][i] + solve(days+1,i,points,n,memo));
    //         }
    //         return maxx;
    //     }
    //     if(memo[days][prevact] == -1){
    //         int maxx = INT_MIN;
    //         for(int i=0;i<3;i++){
    //             if(i == prevact) continue;
    //             maxx = max(maxx,points[days][i] + solve(days+1,i,points,n,memo));
    //         }
    //         memo[days][prevact] = maxx;
    //     }
    //     return memo[days][prevact];
    // }
    
    // ii) Bottom-Up approach :
    
    // int maximumPoints(vector<vector<int>>& points,int n){
    //     vector<vector<int>> tab(n+1,vector<int> (3));
    //     tab[n][0] = tab[n][1] = tab[n][2] = 0;
    //     for(int i=n-1;i>=1;i--){
    //         for(int j=0;j<3;j++){
    //             int maxx = INT_MIN;
    //             for(int k=0;k<3;k++){
    //                 if(k == j) continue;
    //                 maxx = max(maxx,points[i][k] + tab[i+1][k]);
    //             }
    //             tab[i][j] = maxx;
    //         }
    //     }
    //     int ans = max(points[0][0] + tab[1][0],points[0][1] + tab[1][1]);
    //     ans = max(ans,points[0][2] + tab[1][2]);
    //     // return max(points[0][0]+tab[1][0] , points[0][1] + tab[1][1] , points[0][2] + tab[1][2]);
    //     return ans;
    // }
    
    // iii) Space optimized approach : 
    
    int maximumPoints(vector<vector<int>>& points,int n){
        vector<int> next(3);
        next[0] = next[1] = next[2] = 0;
        vector<int> temp(3);
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<3;j++){
                int maxx= INT_MIN;
                for(int k=0;k<3;k++){
                    if(k==j) continue;
                    maxx = max(maxx, points[i][k] + next[k]);
                }
                temp[j] = maxx;
            }
            next = temp;
        }
        int ans = max(points[0][0]+next[0],points[0][1]+next[1]);
        ans = max(ans,points[0][2]+next[2]);
        return ans;
    }