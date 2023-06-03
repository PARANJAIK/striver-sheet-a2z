// Q) Ways to color a 3xN board -> https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

// Ans) 

// i) My COOL approach : Basically in this question:

// >> State "one" represents that column is filled using 2 colours eg(R G R) format.
// >> State "two" represents that column is filled using 3 colours eg(R G B) format.
// >> If the prev column is filled in state "one" -> Then there are -> 7 ways to fill present column in state "one".
//                                                                  -> 10 ways to fill present column in state "two".
// >> If the prev column is filled in state "two" -> Then there are -> 5 ways to fill present column in state "one".
//                                                                  -> 11 ways to fill present column in state "two".
// >> For the first column we have -> 12 ways to fill in state "one".
//                                 -> 24 ways to fill in state "two".

pair<int,int> p[3] = {{12,24},{7,10},{5,11}};
int M = 1e9 + 7;
#define ll long long 

ll mysolve(int ind,int prev,int n,vector<vector<ll>>& memo){
    if(ind == n){
        return 1;
    }
    if(memo[ind][prev] != -1) return memo[ind][prev];
    ll ans = 0;
    ll one = p[prev].first;
    ll two = p[prev].second;
    ans = (ans%M + (one*mysolve(ind+1,1,n,memo)%M)%M)%M;
    ans = (ans%M + (two*mysolve(ind+1,2,n,memo)%M)%M)%M;
    return memo[ind][prev] = ans%M;
}

int Solution::solve(int n){
    vector<vector<ll>> memo(n+1,vector<ll> (3,-1));
    return mysolve(0,0,n,memo);
}

// ii) Other's approach : (MINE IF FAR BEST, BUT ALSO JUST HAVE A LOOK)

// struct triplet{

//     int x,y,z;

// };


// #define mod 1000000007

// map<string,int> mp;


// int arch(int i,int j,int k,int col,vector<triplet> &v,vector<vector<vector<vector<int>>>> &dp){

//     if(col==-1) return 1;

//     int ans=0;

//     if(dp[i][j][k][col]!=-1) return dp[i][j][k][col]%mod;

//     for(int ii=0;ii<36;ii++){

//         if(v[ii].x!=i && v[ii].y!=j && v[ii].z!=k){

//             ans+=arch(v[ii].x,v[ii].y,v[ii].z,col-1,v,dp);

//             ans%=mod;

//         }

        

//     }

//     return dp[i][j][k][col]=ans%mod;

// }


// int Solution::solve(int A) {

//     mp.clear();

//     vector<triplet> v;

//     for(int i=0;i<4;i++){

//         for(int j=0;j<4;j++){

//             for(int k=0;k<4;k++){

//                 if(i!=j && j!=k) v.push_back({i,j,k});

//             }

//         }

//     }

//     vector<vector<vector<vector<int>>>> dp(5,vector<vector<vector<int>>> (5,vector<vector<int>> (5,vector<int> (A,-1))));

//     return arch(4,4,4,A-1,v,dp)%mod;

    

// }
