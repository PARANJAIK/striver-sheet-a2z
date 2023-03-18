// Q) 0-1 Knapsack -> https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=0-1-knapsack-problem0945

    // Ans) 
    
    // i) Top-down approach :
    
    // int knapSack(int w, int wt[], int val[], int n) 
    // { 
    //   // Your code here
    //   vector<vector<int>> memo(n+1,vector<int> (w+1,-1));
    //   return solve(0,w,wt,val,n,memo);
    // }
    
    // int solve(int index,int w,int wt[],int val[],int n,vector<vector<int>>& memo){
    //     if(index == n || w==0){
    //         return 0;
    //     }
    //     if(memo[index][w] == -1){
    //         int noconsider = solve(index+1,w,wt,val,n,memo);
    //         int consider = 0;
    //         if(wt[index] <= w) consider = val[index] + solve(index+1,w-wt[index],wt,val,n,memo);
    //         memo[index][w] = max(noconsider,consider);
    //     }
    //     return memo[index][w];
    // }
    
    // ii) Bottom-up approach : 
    
    int knapSack(int w,int wt[],int val[],int n){
        vector<vector<int>> tab(n+1,vector<int> (w+1));
        for(int i=0;i<n+1;i++){
            tab[i][0] = 0;
        }
        for(int j=0;j<w+1;j++){
            tab[n][j] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<w+1;j++){
                if(wt[i] <= j) tab[i][j] = max(tab[i+1][j],val[i]+tab[i+1][j-wt[i]]);
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][w];
    }