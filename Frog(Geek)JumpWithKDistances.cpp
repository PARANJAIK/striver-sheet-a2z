// Q) Minimal Cost -> https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

    // Ans) 
    
    // i) Top-down approach : 
  
    // vector<int> memo;
  
    // int minimizeCost(vector<int>& height, int n, int k) {
    //     // Code here
    //     memo.assign(n+k,-1);
    //     return solve(1,height,n,k);
    // }
    
    // int solve(int stone,vector<int>& height,int n,int k){
    //     if(stone == n){
    //         return 0;
    //     }
    //     else if(stone > n){
    //         return INT_MAX;
    //     }
    //     if(memo[stone] == -1){
    //         int minn = INT_MAX;
    //         for(int i=1;i<=k;i++){
    //             int x = solve(stone+i,height,n,k);
    //             if(stone+i <= n){
    //                 minn = min(minn,x+abs(height[stone+i-1] - height[stone-1]));
    //             }
    //         }
    //         memo[stone] = minn;
    //     }
    //     return memo[stone];
    // }
    
    // ii) Bottom-up approach : 
    
    int minimizeCost(vector<int>& height,int n,int k){
        int tab[n+k];
        tab[n] = 0;
        for(int i=n+1;i<n+k;i++){
            tab[i] = INT_MAX;
        }
        for(int i=n-1;i>=1;i--){
            int minn = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i+j <= n) minn = min(minn,tab[i+j] + abs(height[i+j-1] - height[i-1]));
            }
            tab[i] = minn;
        }
        return tab[1];
    }