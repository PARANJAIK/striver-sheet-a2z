// Q) Rod Cutting -> https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rod-cutting0840

    // Ans) 
    
    // i) Top-down approach : 
  
    // int cutRod(int price[], int n) {
    //     //code here
    //     vector<vector<int>> memo(n+1,vector<int> (n+1,-1));
    //     return solve(0,n,n,price,memo);
    // }
    
    // int solve(int index,int maxlength,int n,int price[],vector<vector<int>>& memo){
    //     if(index == n){
    //         return 0;
    //     }
    //     if(maxlength == 0){
    //         return 0;
    //     }
    //     if(memo[index][maxlength] == -1){
    //         if(index+1 <= maxlength) memo[index][maxlength] = max(solve(index+1,maxlength,n,price,memo),price[index] + solve(index,maxlength-index-1,n,price,memo));
    //         else memo[index][maxlength] = solve(index+1,maxlength,n,price,memo);
    //     }
    //     return memo[index][maxlength];
    // }
    
    // ii) Bottom-up approach : 
    
    int cutRod(int price[],int n){
        vector<vector<int>> tab(n+1,vector<int> (n+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==n || j==0) tab[i][j] = 0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<n+1;j++){
                if(i+1 <= j) tab[i][j] = max(tab[i+1][j],price[i] + tab[i][j-i-1]);
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][n];
    }