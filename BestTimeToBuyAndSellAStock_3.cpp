//    Q) Best Time to buy and sell stock III -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

    // Ans)

    // i) My Recursive Top-down Approach :

    // int maxProfit(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<vector<int>>> memo(n,vector<vector<int>> (2,vector<int> (3,-1)));
    //     return solve(0,1,2,prices,memo);
    // }

    // int solve(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& memo){
    //     int n = prices.size();
    //     if(i == n || cap == 0){
    //         return 0;
    //     }
    //     if(memo[i][buy][cap] == -1){
    //        if(buy){
    //            memo[i][buy][cap] = max(-prices[i] + solve(i+1,0,cap,prices,memo),solve(i+1,1,cap,prices,memo));
    //        }
    //        else{
    //            memo[i][buy][cap] = max(prices[i] + solve(i+1,1,cap-1,prices,memo),solve(i+1,0,cap,prices,memo));
    //        }
    //     }
    //     return memo[i][buy][cap];
    // }

    // ii) My Recursive Bottom-Up approach:

    // int maxProfit(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<vector<int>>> tab(n+1,vector<vector<int>> (2,vector<int> (3)));
    //     for(int i=0;i<n+1;i++){
    //         tab[i][0][0] = 0;
    //         tab[i][1][0] = 0;
    //         if(i == n){
    //             tab[i][0][1] = tab[i][1][1] = tab[i][0][2] = tab[i][1][2] = 0;
    //         }
    //     }
    //     for(int i=n-1;i>=0;i--){
    //        for(int j = 0;j<=1;j++){
    //            for(int k=1;k<=2;k++){
    //                if(j){
    //                    tab[i][j][k] = max(-prices[i] + tab[i+1][0][k],tab[i+1][1][k]);
    //                }
    //                else{
    //                    tab[i][j][k] = max(prices[i] + tab[i+1][1][k-1],tab[i+1][0][k]);
    //                }
    //            }
    //        }
    //     }
    //     return tab[0][1][2];
    // }

    // iii) My Space Optimized Bottom-Up approach:

     int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> next(2,vector<int> (3,0));
        vector<vector<int>> cur(2,vector<int> (3,0));
        // next[0][1] = next[1][1] = next[0][2] = next[1][2] = next[0][0] = next[1][0] = 0; // we can initialise the elements of next with 0 instead of writing the base cases because we any how return 0 in the base case.
        for(int i=n-1;i>=0;i--){
        //    cur[0][0] = cur[1][0] = 0;  // we can initialise the elements of cur as zero....
           for(int j = 0;j<=1;j++){
               for(int k=1;k<=2;k++){
                   if(j){
                       cur[j][k] = max(-prices[i] + next[0][k],next[1][k]);
                   }
                   else{
                       cur[j][k] = max(prices[i] + next[1][k-1],next[0][k]);
                   }
               }
           }
           next = cur;
        }
        return next[1][2];
    }

    // iv) My initial Almost Passed Yet failed approach : 

    // const int N = 1e5 + 1;
    // vector<int> memo;

    // int maxProfit(vector<int>& prices,int i=0){
    //     int n = prices.size();
    //     if(i==0){
    //         memo.assign(N,-1);
    //     }
    //     if(i == n-1){
    //         return 0;
    //     }
    //     int ans = 0;
    //     // case 1
    //     ans = max(ans,maxProfit(prices,i+1));
    //     // case 2
    //     for(int j = i+1;j < n;j++){
    //         ans = max(ans,prices[j]-prices[i]+single(prices,j+1,memo));
    //     }
    //     // case 3
    //     ans = max(ans,single(prices,0,memo));
    //     return ans;
    // }

    // int single(vector<int>& prices,int j,vector<int>& memo){
    //     int minTillNow = INT_MAX;
    //     int ans = 0;
    //     if(memo[j] == -1){
    //     for(int i=j;i<prices.size();i++){
    //         int currprofit = prices[i] - minTillNow;
    //         if(currprofit > ans) ans = currprofit;
    //         if(prices[i] < minTillNow) minTillNow = prices[i];
    //     }
    //     return memo[j] = ans;
    //     }
    //     return memo[j];
    // }