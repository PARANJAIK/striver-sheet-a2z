// Q) Subarray Sum equals k -> https://leetcode.com/problems/subarray-sum-equals-k/description/

    // Ans) 

    // i) O(N) approach (USING HASHMAP) :

    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int ans = 0;
    //     map<int,int> m;
    //     int sum = 0;
    //     m[0] = 1;
    //     for(int i=0;i<n;i++){
    //        sum += nums[i];
    //        if(m[sum-k]!=0){
    //            ans += m[sum-k];
    //        }
    //        m[sum]++;
    //     }
    //     return ans;
    // }