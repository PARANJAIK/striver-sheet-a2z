// Q) 4Sum Problem -> https://leetcode.com/problems/4sum/description/
                    // -> https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22


    //  Ans)

    // i) The first approach can be to first sort the array and then use three nested loops and try to search for the required element in the right part of the array using binary search. But this is not at all the optimal approach .

    // ii) The optimal approach is to sort the array first and then use two nested loops and then use two pointer approach solve it further as like we did in 3sum problem.          

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                long long int temp1 = 1LL*target - nums[i];
                for(int j=i+1;j<n;j++){
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
                        long long int temp2 = temp1 - nums[j];
                        int low = j+1,high = n-1;
                        while(low < high){
                            if(nums[low] + nums[high] == temp2){
                                vector<int> tempv;
                                tempv.push_back(nums[i]);
                                tempv.push_back(nums[j]);
                                tempv.push_back(nums[low]);
                                tempv.push_back(nums[high]);
                                ans.push_back(tempv);
                                while(low < high && nums[low]==nums[low+1]) low++;
                                while(low < high && nums[high]==nums[high-1]) high--;
                                low++;high--;
                            }
                            else if(nums[low] + nums[high] > temp2){
                                high--;
                            }
                            else{
                                low++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }