// Q) Unbounded knapsack -> https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

    // Ans) 
    
    // i) Top-down approach :

    // int knapSack(int n, int w, int val[], int wt[])
    // {
    //     // code here
    //     vector<vector<int>> memo(n+1,vector<int>(w+1,-1));
    //     return solve(0,n,w,wt,val,memo);
    // }
    
    // int solve(int index,int n,int w,int wt[],int val[],vector<vector<int>>& memo){
    //     if(index == n || w == 0){
    //         return 0;
    //     }
    //     if(memo[index][w] == -1){
    //         if(wt[index] <= w) memo[index][w] = max(solve(index+1,n,w,wt,val,memo),val[index] + solve(index,n,w-wt[index],wt,val,memo));
    //         else memo[index][w] = solve(index+1,n,w,wt,val,memo);
    //     }
    //     return memo[index][w];
    // }
    
    // ii) Bottom-Up approach : 
    
    int knapSack(int n,int w,int val[],int wt[]){
        vector<vector<int>> tab(n+1,vector<int> (w+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==n || j==0) tab[i][j] = 0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<w+1;j++){
                if(wt[i] <= j) tab[i][j] = max(tab[i+1][j],val[i] + tab[i][j-wt[i]]);
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][w];
    }