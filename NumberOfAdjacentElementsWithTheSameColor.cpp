// Q) Number of Adjacent Elements With the Same Color -> https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/

    // i) My working approach : 

    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        int size = q.size();
        vector<int> ans(size,0);
        vector<int> nums(n,0);
        ans[0] = 0;
        nums[q[0][0]] = q[0][1];
        for(int i=1;i<size;i++){
            int index = q[i][0];
            int color = q[i][1];
            if(nums[index] == 0){
                nums[index] = color;
                int x = 0;
                if(index > 0 && nums[index-1] == color) x++;
                if(index < n-1 && nums[index+1] == color) x++;
                ans[i] = ans[i-1] + x;
            }
            else{
                int x = 0;
                if(index-1 >=0 && nums[index-1] == nums[index]) x--;
                if(index+1 < n && nums[index+1] == nums[index]) x--;
                nums[index] = color;
                if(index > 0 && nums[index-1] == color) x++;
                if(index < n-1 && nums[index+1] == color) x++;
                ans[i] = ans[i-1] + x;
            }
        }
        return ans;
    }    

    // ii) My initial failed approach : (JUST A SMALL MISTAKE IN UNDERSTANDING THE APPROACH)

    // vector<int> colorTheArray(int n, vector<vector<int>>& q) {
    //     int size = q.size();
    //     vector<int> left(n,0),right(n,0);
    //     vector<int> nums(n,0);
    //     vector<int> ans(size,0);
    //     ans[0] = 0;
    //     nums[q[0][0]] = q[0][1];
    //     for(int i=1;i<size;i++){
    //         int index = q[i][0];
    //         int color = q[i][1];
    //         if(nums[index] == 0){
    //             nums[index] = color;
    //             int left=index-1,right=index+1;
    //             int x = 0;
    //             while(left >= 0 && nums[left] == color) x++;
    //             while(right < n && nums[right] == color) x++;
    //             ans[i] = ans[i-1] + x;
    //         }
    //         else{
    //             ans[i] = ans[i-1];
    //             if(index-1 >=0 && nums[index-1] == nums[index]) ans[i]--;
    //             if(index+1 < n && nums[index+1] == nums[index]) ans[i]--;
    //             int left=index-1,right=index+1;
    //             int x = 0;
    //             while(left >= 0 && nums[left] == color) x++;
    //             while(right < n && nums[right] == color) x++;
    //             ans[i] += x;
    //         }
    //     }
    //     return ans;
    // }
