// Q) Climbing Stairs -> https://leetcode.com/problems/climbing-stairs/description/

    // Ans) 

    //  Using simple recursion wont work, TLE will come. Using DP works.

    // i) Recursion followed by memoization(TOP DOWN APPROACH):

    // vector<int> memo;

    // int climbStairs(int n) {
    //     memo.assign(n+2,-1);
    //     return solve(0,n);
    // }

    // int solve(int curstep,int n){
    //     if(memo[curstep]!=-1) return memo[curstep];
    //     if(curstep >= n){
    //         if(curstep == n) return 1;
    //         else return 0;
    //     }
    //     int one = solve(curstep+1,n);
    //     int two = solve(curstep+2,n);
    //     return memo[curstep] = one + two;
    // }

    // ii) Tabulation (BOTTOM UP APPROACH) :

    int climbStairs(int n){
        vector<int> memo(n+1);
        memo[n] = 1;
        memo[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            memo[i] = memo[i+1] + memo[i+2];
        }
        return memo[0];
    }