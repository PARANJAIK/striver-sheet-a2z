// Q) Jump Game Array -> https://www.interviewbit.com/problems/jump-game-array/

// Ans) 

// i) My approach : (ITS COOL dp):

// int Solution::canJump(vector<int> &a){
//     int n = a.size();
//     vector<int> dp(n,0);
//     dp[n-1] = 1;
//     for(int i=n-2;i>=0;i--){
//         bool flag = false;
//         for(int j=1;j<=a[i];j++){
//             if(dp[i+j] == 1){
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag) dp[i] = 1;
//         else dp[i] = 0; 
//     }
//     return dp[0];
// }

// ii) Other's approach : (IT IS GREEDY):

int Solution::canJump(vector<int>& a){
    int maxlen = 0;
    for(int i=0;i<a.size() && i <= maxlen;i++) maxlen = max(i + a[i],maxlen);
    return (maxlen >= a.size()-1) ? 1 : 0;
}
