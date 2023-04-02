// Q) Partition Array for Maximum Sum -> https://leetcode.com/problems/partition-array-for-maximum-sum/description/
  
//    Ans)

    // i) TOP-DOWN APPROACH : 

    // int maxSumAfterPartitioning(vector<int>& arr,int k){
    //     int n = arr.size();
    //     if(n == 0) return 0;
    //     if(n == 1) return arr[0];
    //     vector<int> memo(n,-1);
    //     return solve(0,arr,k,memo);
    // }

    // int solve(int i,vector<int>& arr,int k,vector<int>& memo){
    //     if(i == arr.size()){
    //         return 0;
    //     }
    //     int n = arr.size();
    //     if(memo[i] != -1) return memo[i];
    //     int curmax = INT_MIN;
    //     int temp = INT_MIN;
    //     int len = 0;
    //     for(int h = i;h<i+k && h<n;h++){
    //         len++;
    //         if(arr[h] > curmax) curmax = arr[h];
    //         temp = max(temp,len*curmax + solve(h+1,arr,k,memo));
    //     }
    //     return memo[i] = temp;
    // }

    // ii) BOTTOM-UP APPROACH : 

    int maxSumAfterPartitioning(vector<int>& arr,int k){
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        vector<int> tab(n+1,0);
        for(int i=n-1;i>=0;i--){
            int curmax = INT_MIN;
            int temp = INT_MIN;
            int len = 0;
            for(int h=i;h<i+k && h<n;h++){
                len++;
                if(arr[h] > curmax) curmax = arr[h];
                temp = max(temp,len*curmax + tab[h+1]);
            }
            tab[i] = temp;
        }
        return tab[0];
    }

    // iii) My initial approach (WORKS BUT LITTLE SLOW AND TWO VARIABLES ARE ACTUALLY NOT REQUIRED): (TOP-DOWN)

    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     if(n == 0) return 0;
    //     if(n == 1) return arr[0];
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(0,n-1,arr,k,memo);
    // }

    // int solve(int i,int j,vector<int>& arr,int k,vector<vector<int>>& memo){
    //     if(i == j){
    //         return arr[i];
    //     }
    //     if(i > j){
    //         return 0;
    //     }
    //     if(memo[i][j] != -1) return memo[i][j];
    //     int curmax = INT_MIN;
    //     int temp = INT_MIN;
    //     int len = 0;
    //     for(int h = i;h < i+k && h<=j;h++){
    //         len++;
    //         if(arr[h] > curmax) curmax = arr[h];
    //         temp = max(temp,len*curmax + solve(h+1,j,arr,k,memo));
    //     }
    //     return memo[i][j] = temp;
    // }