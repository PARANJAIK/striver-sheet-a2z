// Q) Binary Subarrays with Sum -> https://leetcode.com/problems/binary-subarrays-with-sum/description/

    // Ans)

    // i) 1st approach : 

    // int numSubarraysWithSum(vector<int>& A, int S) {
    //     unordered_map<int, int> c({{0, 1}});
    //     int psum = 0, res = 0;
    //     for (int i : A) {
    //         psum += i;
    //         res += c[psum - S];
    //         c[psum]++;
    //     }
    //     return res;
    // }

    // ii) 2nd approach : (BETTER one)

    int sumUtil(vector<int>&nums, int goal) {
        int n=nums.size();
        int ans=0; int sum=0;
        int j=0;
        if(goal<0)
            return 0;
        for(int i=0;i<n;i++) {
            goal-=nums[i];

            while(goal<0) {
                goal+=nums[j];
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumUtil(nums,goal)-sumUtil(nums, goal-1);
    }

    // iii) My approach (FAILED): (ALL SUBARRAYS ARE NOT GETTING CONSIDERED IN MINE)

    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int sum = 0;
    //     int ans = 0;
    //     int i=0,j=0;
    //     while(j < nums.size()){
    //         if(nums[j] == 0){
    //             if(sum == goal) ans++;
    //             j++;
    //         }
    //         else{
    //             if(sum < goal){
    //                 sum += nums[j];
    //                 j++;
    //             }
    //             else if(sum == goal){
    //                 // ans++;
    //                 while(sum == goal){
    //                     ans++;
    //                     sum = sum - nums[i];
    //                     i++;
    //                 }
    //                 sum += nums[j];
    //                 j++;
    //             }
    //         }
    //     }
    //     while(sum == goal){
    //         ans++;
    //         sum = sum - nums[i];
    //         i++;
    //     }
    //     return ans;
    // }
