// Q) Single Number -> https://leetcode.com/problems/single-number/

    // Ans) 

    // i) XOR approach : 

    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;
    }