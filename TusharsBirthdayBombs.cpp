// Q) Tushar's Birthday Bombs -> https://www.interviewbit.com/problems/tushars-birthday-bombs/

// ii) Proper approach : 

vector<int> Solution::solve(int a,vector<int>& b){
    int n = b.size();
    vector<int> dp(a+1,0);
    vector<int> index(a+1,0);
    for(int i=0;i<=a;i++){
        for(int j=0;j<n;j++){
            if(b[j] <= i){
                if(dp[i-b[j]] + 1 > dp[i]){
                    dp[i] = dp[i-b[j]] + 1;
                    index[i] = j;
                }
            }
        }
    }
    vector<int> ans;
    while(a > 0 && a >= b[index[a]]){
        ans.push_back(index[a]);
        a = a - b[index[a]];
    }
    return ans;
}

// ans) i) My initial failed approach : 

// bool check(vector<int>& s,vector<int>& t){
//     if(s.size() > t.size()) return true;
//     else if(s.size() < t.size()) return false;
//     else{
//         int size = s.size();
//         bool flag = true;
//         for(int i=0;i<size;i++){
//             if(s[i] < t[i]) break;
//             else if(s[i] > t[i]){
//                 flag = false;
//                 break;
//             }
//         }
//         return flag;
//     }
// }

// vector<int> mysolve(int ind,vector<int>& b,int a,vector<vector<vector<int>>>& memo){
//     int n = b.size();
//     if(ind == n || a == 0){
//         if(!check(ans,temp)) ans = temp;
//         return;  
//     }
//     if(memo[ind][a].size() != 0) return memo[ind][a];
//     vector<int> one,two;
//     // not considering
//     one = mysolve(ind+1,b,a,memo);
//     // considering
//     if(b[ind] <= a){
//         two = mysolve(ind+1,b,a-b[ind],memo);
//     }
//     if(check(one,two)) return memo[ind] = one;
//     else return memo[ind] = two;
// }

// vector<int> Solution::solve(int a, vector<int> &b) {
//     int n = b.size();
//     vector<vector<vector<int>>> memo(n+1,vector<vector<int>> (a+1));
//     // vector<int> temp,ans;
//     return mysolve(0,b,a,memo);
//     // return ans;
// }
