// Q) Minimum Number of Coins -> https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-number-of-coins

    // Ans) 
    
    // i) Greedy Approach : 

    vector<int> minPartition(int amount){
        vector<int> coins = {2000,500,200,100,50,20,10,5,2,1};
        int n = 10;
        vector<int> ans;
        int i=0;
        while(amount>0){
            if(amount>=coins[i]){
                ans.push_back(coins[i]);
                amount -= coins[i];
            }
            else{
                i++;
            }
        }
        return ans;
    }