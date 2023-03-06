// Q) 3Sum -> https://leetcode.com/problems/3sum/description/

    // Ans) 

    // i) My approach : Its good but not at all optimal O(n*n*logM) time complexity. And O(N) + O(M) space complexity.

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     set<vector<int>> s;
    //     int n = nums.size();
    //     unordered_map<int,int> ma;
    //     unordered_map<int,int> m;
    //     for(int i=0;i<n;i++){
    //         m[nums[i]]++;
    //     }
    //     for(int i=0;i<n;i++){
    //         int sum2 = 0 - nums[i];
    //         m[nums[i]]--;
    //         if(ma[nums[i]] != 0) continue;
    //         for(int j=i+1;j<n;j++){
    //             m[nums[j]]--;
    //             if(m[sum2-nums[j]] != 0){
    //                 vector<int> temp;
    //                 temp.push_back(nums[i]);
    //                 temp.push_back(nums[j]);
    //                 temp.push_back(sum2-nums[j]);
    //                 sort(temp.begin(),temp.end());
    //                 s.insert(temp);
    //             }
    //             m[nums[j]]++;
    //         }
    //         m[nums[i]]++;
    //         ma[nums[i]]++;
    //     }
    //     for(auto it : s){
    //         ans.push_back(it);
    //     }
    //     return ans;
    // }

    // ii) Striver's approach(SORTED THE ARRAY AND THEN APPLIED TWO POINTER APPROACH) : Optimal. O(n*n) time complexity and O(1) auxiliary space complexity.

    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        //moves for a
        for(int i=0;i<nums.size()-2;i++){
           if(i==0 || (i>0 && nums[i] != nums[i-1])){
               int lo = i+1,hi = nums.size()-1,sum = 0 - nums[i];
               while(lo < hi){
                   if(nums[lo] + nums[hi] == sum){
                       vector<int> temp;
                       temp.push_back(nums[i]);
                       temp.push_back(nums[lo]);
                       temp.push_back(nums[hi]);
                       ans.push_back(temp);
                       while(lo < hi && nums[lo]==nums[lo+1]) lo++;
                       while(lo < hi && nums[hi]==nums[hi-1]) hi--;
                       lo++;hi--;
                   }
                   else if(nums[lo] + nums[hi] < sum) lo++;
                   else hi--;
               }
           }
        }
        return ans;
    }