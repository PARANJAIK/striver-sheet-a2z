/    Q) Permutations -> https://leetcode.com/problems/permutations/description/

//    Ans) 

    // i) My approach :  

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
    vector<int> vis(n,0);
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0,vis,temp,nums,ans);
    return ans;
    }

    void solve(int index,vector<int>& vis,vector<int>& temp,vector<int>& nums,vector<vector<int>>& ans){
    int n = nums.size();
    if(index == n){
        ans.push_back(temp);
    }
    for(int i=0;i<n;i++){
        if(vis[i] == 1) continue;
        vis[i] = 1;
        temp.push_back(nums[i]);
        solve(index+1,vis,temp,nums,ans);
        temp.pop_back();
        vis[i] = 0;
    }
    return;
}
