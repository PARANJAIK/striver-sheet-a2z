// Q) Maximum Points You Can obtain from cards -> https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

    // Ans) 

    // i) COOL APPROACH :

    // NOTE : THE COOL FACT USED TO SOLVE THE PROBLEM IS THAT ORDER OF PICKING THE CARDS DOESNT MATTER, EVERYTHING THAT MATTERS IS WHAT CARDS YOU PICK AND MORE PROPERLY HOW MANY CARDS YOU PICK FROM START AND END. 

    int maxScore(vector<int>& card,int k){
        int n = card.size();
        int temp = 0;
        for(int i=0;i<k;i++){
            temp += card[i];
        }
        int ans = temp;
        int i = k-1,j = n-1;
        while(i >= 0){
            temp = temp - card[i] + card[j];
            ans = max(ans,temp);
            i--;j--;
        }
        return ans;
    }

    // II) My DP approach : (GIVES TLE, obvious because of constraints)

    // int maxScore(vector<int>& card, int k) {
    //     int n = card.size();
    //     vector<vector<vector<int>>> memo(n,vector<vector<int>> (n,vector<int> (k+1,-1)));
    //     return solve(0,n-1,card,k,memo);
    // }

    // int solve(int i,int j,vector<int>& card,int k,vector<vector<vector<int>>>& memo){
    //     if(k == 0) return 0;
    //     if(i > j){
    //         return 0;
    //     }
    //     else if(i == j){
    //         return card[i];
    //     }
    //     if(memo[i][j][k] != -1) return memo[i][j][k];
    //     long long int temp = 0;
    //     temp = max(1LL*card[i] + 1LL*solve(i+1,j,card,k-1,memo),1LL*card[j] + 1LL*solve(i,j-1,card,k-1,memo));
    //     return memo[i][j][k] = temp;
    // }
