// Q) Split arrays Largest Sum -> https://leetcode.com/problems/split-array-largest-sum/description/

    // Ans) 

    // i) My approach -> Binary Search considering the possible values of answers as the search space.

    bool check(int maxsum,vector<int>& nums,int k){
        int sum = 0;int cnt = 0;
        for(auto num : nums){
            if(sum + num <= maxsum){
                sum += num;
            }
            else{
                cnt++;
                if(num > maxsum) return false;
                sum = num;
            }
        }
        if(sum <= maxsum) cnt++;
        if(cnt <= k) return true;
        else return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = INT_MAX;
        int high = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] < low) low = nums[i];
            high += nums[i];
        }
        while(high-low > 1){
            int mid = (low+high)>>1;
            bool x = check(mid,nums,k);
            if(x){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(check(low,nums,k)) return low;
        else return high;
    }