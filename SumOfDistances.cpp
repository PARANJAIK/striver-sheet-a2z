class Solution {
public:
    // Q) Sum of Distances -> https://leetcode.com/problems/sum-of-distances/description/

    // i) My approach : 

    // vector<long long> distance(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<long long> arr(n);
    //     unordered_map<int,int> last;
    //     vector<pair<int,long long int>> ltr(n);
    //     for(int i=0;i<n;i++){
    //         if(last.find(nums[i]) == last.end()){
    //             last[nums[i]] = i;
    //             ltr[i] = {0,0};
    //         }
    //         else{
    //             int index = last[nums[i]];
    //             ltr[i] = {ltr[index].first+1,ltr[index].second+index};
    //             last[nums[i]] = i;
    //         }
    //     }
    //     unordered_map<int,int> lastt;
    //     vector<pair<int,long long int>> rtl(n);
    //     for(int i=n-1;i>=0;i--){
    //         if(lastt.find(nums[i]) == lastt.end()){
    //             lastt[nums[i]] = i;
    //             rtl[i] = {0,0};
    //         }
    //         else{
    //             int index = lastt[nums[i]];
    //             rtl[i] = {rtl[index].first+1,rtl[index].second+index};
    //             lastt[nums[i]] = i;
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         arr[i] = (1LL*i*(ltr[i].first) - ltr[i].second) + (rtl[i].second - 1LL*(rtl[i].first)*i);
    //     }
    //     return arr;
    // }

    // ii) slightly better implementation:

    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long>ans(n);
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        for (auto it : mp)
        {
            int num = it.first;
            vector<int>& indexes = it.second;
            //======================================================
            long long totalSum = 0;
            for (int index : indexes) totalSum += (long long)index;
            
            long long preSum = 0;
            for (int i = 0; i < indexes.size(); i++)
            {
                int index = indexes[i];
                long long postSum = totalSum - preSum - index;
                
                ans[index] += (index * (long long)i);
                ans[index] -= (preSum);
                ans[index] -= (index * (long long)(indexes.size() - i - 1));
                ans[index] += (postSum);
                
                preSum += index;
            }
            //======================================================
        }
        return ans;
        
        
    }
};
