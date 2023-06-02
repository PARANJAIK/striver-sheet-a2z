// Q) Longest Arithmetic Progression -> https://www.interviewbit.com/problems/longest-arithmetic-progression/

// Ans)

// i) My working approach : Fix the 1st and 2nd elements and hence the common difference is fixed

int Solution::solve(const vector<int>& a){
    unordered_map<int,int> mp;
    int n = a.size();
    if(n <= 2) return n;
    vector<vector<int>> dp(n+1,vector<int> (n+1));
    int ans = 2;
    for(int i=n-2;i>=0;i--){
        mp.clear();
        for(int j=n-1;j>i;j--){
            dp[i][j] = 2;
            int need = 2*a[j] - a[i];
            if(mp.find(need) != mp.end()){
                dp[i][j] = max(dp[i][j],1 + dp[j][mp[need]]);
                ans = max(ans,dp[i][j]);
            }
            mp[a[j]] = j;
        }
    }
    return ans;
}

// ii) My initial approach : (FAILS)

// long long int mysolve(long long int ind,long long int prev,long long int d,vector<unordered_map<long long int,long long int>>& dp,const vector<int>& a){
//     int n = a.size();
//     if(ind == n){
//         return 0;
//     }
//     if(dp[prev][d] != 0) return dp[prev][d];
//     // check if you can consider the ind
//     if(a[ind] - a[prev] == d) return dp[prev][d] = 1 + mysolve(ind+1,ind,d,dp,a);
//     else return dp[prev][d] = mysolve(ind+1,prev,d,dp,a);
// }

// int Solution::solve(const vector<int> &a) {
//     int n = a.size();
//     long long int ans = 1;
//     vector<unordered_map<long long int,long long int>> dp(n);
//     // unordered_map<int,unordered_map<int,int>> dp;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             long long int d = a[j] - a[i];
//             long long int len = 2 + mysolve(j+1,j,d,dp,a);
//             ans = max(ans,len);
//         }
//     }
//     return ans;
// }
