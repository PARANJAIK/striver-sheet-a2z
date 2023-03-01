//    Q) Next Permutation -> https://leetcode.com/problems/next-permutation/

    //   Ans) 

    //   Approach : Iterate the array from backwards, and find the index where nums[index] < nums[index + 1], mark that index as index1. Then again iterate the array from backwards and find the element which is just greater than the element at index1. Mark this element as index2. Now swap index1 and index2 and reverse the array from index1 + 1 to end.

    void nextPermutation(vector<int>& nums) {
        int index1 = -1;
        int index2;
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                index1 = i-1;
                break;
            }
        }
        if(index1 == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            index2 = n-1;
            while(nums[index2] <= nums[index1]) index2--;
            swap(nums[index1],nums[index2]);
            reverse(nums.begin()+index1+1,nums.end());
        }
        return;
    }