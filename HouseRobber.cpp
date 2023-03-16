// Q) House Robber -> https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stickler-theif-

    // Ans) 
    
    // i) Same as maximum sum of non adjacent elements question:
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> memo(n+1,-1);
        return solve(0,arr,n,memo);
    }
    
    int solve(int index,int arr[],int n,vector<int>& memo){
        if(index >= n){
            return 0;
        }
        if(memo[index] == -1){
            int nopick = solve(index+1,arr,n,memo);
            int pick = arr[index] + solve(index+2,arr,n,memo);
            memo[index] = max(nopick,pick);
        }
        return memo[index];
    }