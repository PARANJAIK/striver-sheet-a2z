// Q) Count Number Of Nice Subarrays -> https://leetcode.com/problems/count-number-of-nice-subarrays/description/

    // Ans) 

    // i) My 1st approach : 

    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     queue<int> q;
    //     int n = nums.size();
    //     int i=0,j=0;
    //     int ans = 0;
    //     while(j < n){
    //         if(nums[j]%2 == 0){
    //             j++;
    //         }
    //         else{
    //             if(q.size() < k){
    //                 q.push(j);
    //                 j++;
    //             }
    //             else{
    //                 ans += (q.front()-i+1)*(j-q.back());
    //                 i = q.front() + 1;
    //                 q.pop();
    //                 q.push(j);
    //                 j++;
    //             }
    //         }
    //     }
    //     if(q.size() == k){
    //         ans += (q.front()-i+1)*(j-q.back());
    //     }
    //     return ans;
    // }

    // ii) My 2nd approach : 

    int numberOfSubarrays(vector<int>& nums,int k){
       return solve(nums,k) - solve(nums,k-1);
    }

    int solve(vector<int>& nums,int k){
         int i = 0;
        int ans = 0;
        int j = 0;
        int odd = 0;
        while(j < nums.size()){
            if(nums[j]%2 == 1) odd++;
            while(odd > k){
                if(nums[i]%2 == 1) odd--;
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
