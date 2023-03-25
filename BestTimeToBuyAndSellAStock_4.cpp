// i) Best Time to Buy and sell stock iv -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
                                            // -> https://www.youtube.com/watch?v=IV1dHbk5CDc

    // Ans) 

    // i) Recursive space optimized Bottom-up approach (3D - dp) : 

    // int maxProfit(int cap, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> next(2,vector<int> (cap+1,0));
    //     vector<vector<int>> cur(2,vector<int> (cap+1,0));
    //     // next[0][1] = next[1][1] = next[0][2] = next[1][2] = next[0][0] = next[1][0] = 0; // we can initialise the elements of next with 0 instead of writing the base cases because we any how return 0 in the base case.
    //     for(int i=n-1;i>=0;i--){
    //     //    cur[0][0] = cur[1][0] = 0;  // we can initialise the elements of cur as zero....
    //        for(int j = 0;j<=1;j++){
    //            for(int k=1;k<=cap;k++){
    //                if(j){
    //                    cur[j][k] = max(-prices[i] + next[0][k],next[1][k]);
    //                }
    //                else{
    //                    cur[j][k] = max(prices[i] + next[1][k-1],next[0][k]);
    //                }
    //            }
    //        }
    //        next = cur;
    //     }
    //     return next[1][cap];
    // }

    // ii) Recursive Space Optimized bottom-Up approach (2D - dp) :

    // approach : We consider the index i from 0 to n-1 of the given array and the transaction number from 0 to 2*k -1 where k is the maximum no.of transactions that we can do. i == n and tranNo == 2*k will become the base cases. Main point to be noted is that if tranNo is odd then in it is Sell that we have to do, else if tranNo is even then we have to Buy a Stock.

    int maxProfit(int k,vector<int>& prices){
        int n = prices.size();
        vector<int> next(2*k + 1,0);
        vector<int> cur(2*k + 1,0);
        // initialised to zero because both the base cases : 
        // i) i == n and
        // ii) tranNo. == 2*k return 0;
        for(int ind = n-1;ind>=0;ind--){
            for(int tranNo = 2*k - 1;tranNo>=0;tranNo--){
                if(tranNo % 2 == 0){  // BUY
                     cur[tranNo] = max(-prices[ind] + next[tranNo+1],next[tranNo]);
                }
                else{  // SELL
                     cur[tranNo] = max(prices[ind] + next[tranNo+1],next[tranNo]);
                }
            }
            next = cur;
        }
        return next[0];
    }