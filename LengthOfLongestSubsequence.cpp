// Q) Length of Longest Subsequence -> https://www.interviewbit.com/problems/length-of-longest-subsequence/

// Ans)

// i) Working solution approach using longest increasing subsequence : 

int Solution :: longestSubsequenceLength(const vector<int> &a){
    int n = a.size();
    if(n == 0) return 0;
    vector<int> inc(n,1);
    vector<int> dec(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]) inc[i] = max(inc[i],inc[j]+1);
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[j] < a[i]) dec[i] = max(dec[i],dec[j] + 1);
        }
    }
    int ans = inc[0] + dec[0] - 1;
    for(int i=1;i<n;i++){
        ans = max(ans,inc[i] + dec[i] - 1);
    }
    return ans;
}

// ii) My failed 1st approach : 

// int solve(int ind,int flag,const vector<int>& a,vector<vector<int>>& memo,int prev){
//     int n = a.size();
//     if(ind == n){
//         return 0;
//     }
//     if(memo[ind][flag] != -1) return memo[ind][flag];
//     // considering decreasing 
//     int ans = solve(ind+1,0,a,memo,prev); // not considering current element
//     if(a[ind] < prev) ans = max(ans,1 + solve(ind+1,0,a,memo,a[ind]));
//     // considering increasing if we can
//     if(flag == 1){
//         ans = max(ans,solve(ind+1,1,a,memo,prev)); // not considering current element;
//         if(a[ind] > prev) ans = max(ans,1 + solve(ind+1,1,a,memo,a[ind]));
//     }
//     return memo[ind][flag] = ans;
// }

// int Solution::longestSubsequenceLength(const vector<int> &a){
//     int n = a.size();
//     vector<vector<int>> memo(n+1,vector<int> (2,-1));
//     return max(solve(1,1,a,memo,a[0]),solve(1,0,a,memo,INT_MAX));
// }

// iii) My failed 2nd approach : 

// int solve(int ind,int flag,const vector<int>& a,vector<vector<int>>& memo,int prev){
//     int n = a.size();
//     if(ind == n){
//         return 0;
//     }
//     if(memo[ind][flag] != -1) return memo[ind][flag];
//     int ans;
//     // if there are zero elements in the subsequence right now
//     if(prev == INT_MIN){
//         ans = solve(ind+1,1,a,memo,prev);    // not considering
//         ans = max(ans,1 + solve(ind+1,1,a,memo,a[ind]));  // considering
//     }
//     else{
//         ans = solve(ind+1,flag,a,memo,prev);   // not considering
//         if(a[ind] < prev) ans = max(ans,1 + solve(ind+1,0,a,memo,a[ind]));  // considering
//         else if(a[ind] > prev && flag == 1) ans = max(ans,1 + solve(ind+1,1,a,memo,a[ind]));   // considering
//     }
//     return memo[ind][flag] = ans;
// }

// int Solution::longestSubsequenceLength(const vector<int> &a){
//     int n = a.size();
//     vector<vector<int>> memo(n+1,vector<int> (2,-1));
//     return solve(0,1,a,memo,INT_MIN);
// }
