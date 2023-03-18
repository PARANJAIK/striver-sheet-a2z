// 	Q) Count Subsets with Sum K -> https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

    // Ans) 
    
    // i) Top-down approach : 
	
// 	int M = 1e9 + 7;
	
// 	int perfectSum(int arr[], int n, int sum)
// 	{
//         vector<vector<int>> memo(n+1,vector<int> (sum+1,-1));
//         return solve(0,sum,n,arr,memo);
// 	}
	  
// 	int solve(int index,int sum,int n,int arr[],vector<vector<int>>& memo){
// 	    if(index == n){
// 	        if(sum == 0) return 1;
// 	        else return 0;
// 	    }
// 	   // if(sum == 0) return 1;    // This base condition is wrong because it doesn't count the subsets possible with sum 0 properly.
// 	    if(memo[index][sum] == -1){
// 	        int noconsider = solve(index+1,sum,n,arr,memo);
// 	        int consider = 0;
// 	        if(arr[index] <= sum) consider = solve(index+1,sum-arr[index],n,arr,memo);
// 	        memo[index][sum] = (1LL*noconsider + consider)%M;
// 	    }
// 	    return memo[index][sum];
// 	}

    // ii) Bottom-up approach :

    int M = 1e9+7;
    
    int perfectSum(int arr[],int n,int sum){
        vector<vector<int>> tab(n+1,vector<int> (sum+1));
        tab[n][0] = 1;
        for(int j=1;j<sum+1;j++){
            tab[n][j] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<sum+1;j++){
                if(arr[i] <= j) tab[i][j] = (1LL*tab[i+1][j] + tab[i+1][j-arr[i]])%M;
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][sum];
    }