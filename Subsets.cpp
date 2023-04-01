// Q) Subsets -> https://leetcode.com/problems/subsets/description/

    // i) My approach : 

    // void generate(vector<int>& nums,vector<vector<int>>& ans,vector<int> v,int index){
    //     if(index == nums.size()) return;
    //     generate(nums,ans,v,index+1);
    //     v.push_back(nums[index]);
    //     ans.push_back(v);
    //     generate(nums,ans,v,index+1);
    // }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     int index = 0;
    //     vector<int> v;
    //     ans.push_back(v);
    //     generate(nums,ans,v,index);
    //     return ans;
    // }

    // ii) BitMasking approach : 

    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                if((i>>j)&1 == 1){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }