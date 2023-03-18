// Q) Count Partitions with given difference -> https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

    // Ans) 
    
    // i) Bottom-up approach : 
  
    int M = 1e9+7;
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalsum = 0;
        for(int i=0;i<n;i++){
            totalsum += arr[i];
        }
        if((totalsum + d)%2==1) return 0;
        int sum = (totalsum + d)/2;
        vector<vector<int>> tab(n+1,vector<int> (sum+1));
        tab[n][0] = 1;
        for(int j=1;j<sum+1;j++){
            tab[n][j] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<sum+1;j++){
                if(arr[i] <= j) tab[i][j] = (1LL*tab[i+1][j] + tab[i+1][j - arr[i]])%M;
                else tab[i][j] = tab[i+1][j];
            }
        }
        return tab[0][sum];
    }