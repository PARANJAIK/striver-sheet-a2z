// Q) Geek Jump -> https://practice.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

    // Ans) 
    
    // i) Top-down approach : 
  
    // vector<int> memo;
  
    // int minimumEnergy(vector<int>& height, int n) {
    //     // Code here
    //     memo.assign(n+1,-1);
    //     return solve(0,n,height,-1);
    // }
    
    // int solve(int step,int n,vector<int>& height,int prevstep){
    //     if(step == n){
    //         return INT_MAX;
    //     }
    //     else if(step == n-1){
    //         return abs(height[step]-height[prevstep]);
    //     }
    //     if(memo[step]==-1){
    //         int one = solve(step + 1,n,height,step);
    //         int two = solve(step + 2,n,height,step);
    //         memo[step] = min(one,two); 
    //     }
    //     if(step == 0) return memo[step];
    //     else return memo[step] + abs(height[step]-height[prevstep]);
    // }
    
    // ii) Bottom-up approach : 
    
    int minimumEnergy(vector<int>& height,int n){
        vector<int> tab(n+1);
        height.push_back(height[n-2]);
        tab[n] = INT_MAX;
        tab[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            tab[i] = min(tab[i+1] + abs(height[i+1]-height[i]) , tab[i+2] + abs(height[i+2] - height[i]));
        }
        return tab[0];
    }