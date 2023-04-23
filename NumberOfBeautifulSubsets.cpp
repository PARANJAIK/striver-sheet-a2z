 // Q) The Number of Beautiful Subsets -> https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

    // Ans) 

    // i) My approach : 

    // int beautifulSubsets(vector<int>& nums, int k) {
    //     vector<int> v;
    //     int n = nums.size();
    //     return solve(0,nums,k,v);
    // }
    
    // int solve(int index,vector<int>& nums,int k,vector<int>& v){
    //     int n = nums.size();
    //     if(index == n){
    //         if(v.empty()) return 0;
    //         return 1;
    //     }
    //     if(find(v.begin(),v.end(),nums[index]-k) != v.end() || find(v.begin(),v.end(),nums[index]+k) != v.end()){
    //         return solve(index+1,nums,k,v);
    //     }
    //     else{
    //         // no consider
    //         int no = solve(index+1,nums,k,v);
    //         // yes consider
    //         v.push_back(nums[index]);
    //         int yes = solve(index+1,nums,k,v);
    //         v.pop_back();
    //         return no + yes;
    //     }
    // }

    // ii) better implementation : 
    
    int v[1001];
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        memset(v, 0, sizeof(v));

        return solve(nums, 0, k)-1;
    }
    int solve(vector<int>& nums, int i, int k){
        if(i == nums.size()) return 1;

        int res = 0;

        if(nums[i]-k < 0 || v[nums[i]-k] == 0){
            v[nums[i]]++;
            res += solve(nums, i+1, k);
            v[nums[i]]--;
        }

        res += solve(nums, i+1, k);

        return res;
    }

