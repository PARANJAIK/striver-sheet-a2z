//    Q) 2SumProblem -> https://leetcode.com/problems/two-sum/description/

    //   Ans) 

    //   i) Approach : Just maintain a map which stores the index of occurence of an array element against the
        //  array element. And while iterating over the array if at any index you find target - nums[index] is 
        //  already present in the map, then you got your answer.

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int temp = target - nums[i];
            if(m.find(temp) != m.end()){
                return {m[temp],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }