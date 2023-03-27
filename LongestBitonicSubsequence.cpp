// 	Q) Longest Bitonic subsequence -> https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-bitonic-subsequence0824

    // Ans) 
    
    // i) O(n*n) time and O(n) dp table space approach : 
	
	int LongestBitonicSequence(vector<int> nums){
        int n = nums.size();
        vector<int> fwddp(n,1),dowdp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && 1 + fwddp[j] > fwddp[i]){
                    fwddp[i] = 1 + fwddp[j];
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i] > nums[j] && 1 + dowdp[j] > dowdp[i]){
                    dowdp[i] = 1 + dowdp[j];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,fwddp[i] + dowdp[i] -1);
        }
        return ans;
    }
    
    // ii) My initial failed attempt : 
	
	
// 	int LongestBitonicSequence(vector<int>nums)
// 	{
// 	    // code here
// 	    int n = nums.size();
// 	    vector<vector<vector<int>>> memo(n,vector<vector<int>> (2,vector<int> (n+1,-1)));
// 	    return solve(0,1,0,nums,memo);
// 	}
	
// 	int solve(int i,int flag,int prevind,vector<int>& nums,vector<vector<vector<int>>>& memo){
// 	    int n = nums.size();
// 	    if(i == n){
// 	        return 0;
// 	    }
// 	    if(memo[i][flag][prevind] == -1){
// 	        // no consider case
// 	        int ans = solve(i+1,flag,prevind,nums,memo);
// 	        // consider case
// 	            if(flag == 0){
// 	                if(arr[prevind] > arr[i]) ans = max(ans,1 + solve(i+1,0,i+1,nums,memo));
// 	            }
// 	            else{
// 	                // true case
// 	                if(arr[])
// 	                ans = max(ans,1 + solve(i+1,1,len+1,nums,memo));
// 	                // false case
// 	                if(prevind >= 1) ans = max(ans,1 + solve(i+1,0,len+1,nums,memo));
// 	            }
// 	            memo[i][flag][len] = ans;
// 	    }
// 	    return memo[i][flag][len];
// 	}