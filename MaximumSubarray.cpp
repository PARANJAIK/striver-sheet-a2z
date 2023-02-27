//    Q) Maximum Subarray -> https://leetcode.com/problems/maximum-subarray/description/
                     //   -> https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6

    //  Ans)

    // i) My Initial Approach : while traversing i found the cumulative sum and i have maintained a priority queue to give me the minimum cumulative sum that has appeared till that point. Then if sum - pq.top() was greater than the current ans, then i updated the ans to sum - pq.top(). And then pushed the current sum into pq.

    // int maxSubArray(vector<int>& nums) {
    //     priority_queue<int,vector<int>,greater<int>> pq;
    //     pq.push(0);
    //     int sum = 0;
    //     int ans = INT_MIN;
    //     for(int i=0;i<nums.size();i++){
    //        sum += nums[i];
    //        int temp = sum - pq.top();
    //        if( temp > ans) ans = temp;
    //        pq.push(sum);
    //     }
    //     return ans;
    // }

    // ii) My Optimal Approach : (priority_queue is not at all needed), Every thing is same like my initial approach except that i used a minTillNow variable to get the minimum sum till that point instead of using a priority queue.

    int maxSubArray(vector<int>& nums){
        int minTillNow = 0;
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum - minTillNow > ans) ans = sum - minTillNow;
            minTillNow = min(sum,minTillNow);
        }
        return ans;
    }

//    iii) Striver's Approach : (KADANE'S ALGORITHM), In this we do cumulative sum and at every point we make sum = 0 if sum < 0. Means we dont carry forward the subarrays with negative sum since we need maximum sum subarray. At every point we whether that could be the maximum sum and update the maxi.

    // int maxSubArray(vector<int> &nums){
    //     int sum = 0;
    //     int maxi = INT_MIN;
    //     for(auto it : nums){
    //         sum += it;
    //         maxi = max(sum,maxi);
    //         if(sum < 0) sum = 0;
    //     }
    //     return maxi;
    // }