// Q) Subset Sum equal to given target -> https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sum-problem-1611555638

    // Ans) 
    
    // i) 1st recursive approach : THIS APPROACH OBVIOUSLY WONT WORK BUT THE POINT TO BE NOTED IS THAT WE CANT MEMOIZE IT IF WE USE THIS RECURSIVE APPROACH.

    // bool isSubsetSum(vector<int>arr, int sum){
    //     // code here 
    //     int n = arr.size();
    //     return solve(0,0,n,arr,sum);
    // }
    
    // bool solve(int index,int ss,int n,vector<int>& arr,int sum){
    //     if(index == n){
    //         if(ss == sum) return true;
    //         else return false;
    //     }
    //     bool noconsider = solve(index+1,ss,n,arr,sum);
    //     bool consider = solve(index+1,ss+arr[index],n,arr,sum);
    //     return noconsider || consider;
    // }
    
    // ii) Proper Recursive approach : WE CAN MEMOIZE THIS RECURSIVE APPROACH (TOP-DOWN approach) : 
    
    // bool isSubsetSum(vector<int> arr,int sum){
    //     int n = arr.size();
    //     vector<vector<int>> memo(n,vector<int> (sum+1,-1));
    //     return solve(0,sum,n,arr,memo);
    // }
    
    // bool solve(int index,int sum,int n,vector<int>& arr,vector<vector<int>>& memo){
    //     if(index == n){
    //         if(sum == 0) return true;
    //         else return false;
    //     }
    //     if(sum == 0) return true;
    //     if(memo[index][sum] == -1){
    //     bool noconsider = solve(index+1,sum,n,arr,memo);
    //     bool consider = false;
    //     if(arr[index] <= sum) consider = solve(index+1,sum-arr[index],n,arr,memo);
    //     memo[index][sum] = noconsider || consider;
    //     }
    //     return memo[index][sum];
    // }
    
    // iii) Bottom-Up approach : 
    
    bool isSubsetSum(vector<int> arr,int sum){
        int n = arr.size();
        vector<vector<int>> tab(n+1,vector<int> (sum+1));
        for(int j=0;j<sum+1;j++){
            tab[n][j] = false;
        }
        for(int i=0;i<n+1;i++){
            tab[i][0] = true;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=sum;j++){
                if(arr[i] <= j) tab[i][j] = (tab[i+1][j] || tab[i+1][j-arr[i]]);
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][sum];
    }