// Q) Matrix Chain Multiplication -> https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication

    // Ans)
    
    // i) Partition-DP top down approach : 

    // int matrixMultiplication(int n, int arr[])
    // {
    //     // code here
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(1,n-1,arr,memo);
    // }
    
    // int solve(int i,int j,int arr[],vector<vector<int>>& memo){
    //     if(i == j){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         memo[i][j] = INT_MAX;
    //         for(int k=i;k<j;k++){
    //             int temp = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,memo) + solve(k+1,j,arr,memo);
    //             memo[i][j] = min(memo[i][j],temp);
    //         }
    //     }
    //     return memo[i][j];
    // }
    
    // ii) Bottom-Up approach : 
    
    int matrixMultiplication(int n,int arr[]){
        vector<vector<int>> tab(n+1,vector<int> (n+1,0));
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                if(i == j){
                    tab[i][j] = 0;
                    continue;
                }
                tab[i][j] = INT_MAX;
                for(int k=i;k<j;k++){
                    int temp = arr[i-1]*arr[k]*arr[j] + tab[i][k] + tab[k+1][j];
                    tab[i][j] = min(tab[i][j],temp);
                }
            }
        }
        return tab[1][n-1];
    }