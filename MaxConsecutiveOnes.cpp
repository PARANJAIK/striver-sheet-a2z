// Q) Max Consecutive Ones III -> https://leetcode.com/problems/max-consecutive-ones-iii/

    // Ans) 

    // i) My approach : 
    
    int longestOnes(vector<int>& nums,int k){
        queue<int> q;
        int n = nums.size();
        int i=0;
        int ans = 0;
        int j;
        for(j=0;j<n;j++){
            if(nums[j] == 0){
                if(q.size() < k){
                    q.push(j);
                }
                else{
                    ans = max(ans,j-i);
                    if(q.empty()){        // k = 0 case
                        i = j + 1;
                        continue;
                    }
                    i = q.front() + 1;
                    q.pop();
                    q.push(j);
                }
            }
        }
        ans = max(ans,j-i);
        return ans;
    }

    // ii) Someone's approach, works with same complexity as mine. But I didn't understand how this logic works.

    //  int longestOnes(vector<int>& A, int K) {
    //     int i = 0, j;
    //     for (j = 0; j < A.size(); ++j) {
    //         if (A[j] == 0) K--;
    //         if (K < 0 && A[i++] == 0) K++;
    //     }
    //     return j - i;
    // }

    // iii) My first attemp(TRIED TO USE DP)(BUT REALISED THAT IT IS GETTING COMPLICATED WHEN I DECIDE TO CONSIDER A PARTICULAR INDEX, CERTAIN ELEMENTS ARE GETTING REPEATED. SO IT BECOMES COMPLICATED)

    // int longestOnes(vector<int>& nums, int k) {
    //     vector<int> req;
    //     if(nums[0] == 0) req.push_back(0);
    //     int cnt = 1;
    //     for(int i=1;i<nums.size();i++){
    //        if(nums[i] == nums[i-1]) cnt++;
    //        else{
    //            req.push_back(cnt);
    //            cnt = 1;
    //        }
    //     }
    //     req.push_back(cnt);
    //     int n = req.size();
    //     vector<vector<int>> memo(n,vector<int> (k+1,-1));
    //     return solve(1,k,req,memo);
    // }

    // int solve(int i,int k,vector<int>& req,vector<vector<int>>& memo){
    //     int n = req.size();
    //     if(i == n){
    //         return 0;
    //     }
        
    // }
