// Q) Sliding Window Maximum -> https://leetcode.com/problems/sliding-window-maximum/

    // Ans)

    // i) Striver's approach : 

    // vector<int> maxSlidingWindow(vector<int>& nums,int k){
    //     deque<int> dq;
    //     vector<int> ans;
    //     for(int i=0;i<nums.size();i++){
    //         if(!dq.empty() && dq.front() == i-k) dq.pop_front();
    //         while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
    //         dq.push_back(i);
    //         if(i>=k-1) ans.push_back(nums[dq.front()]);
    //     }
    //     return ans;
    // }

    // ii) Other's solution (BEST TIME COMPLEXITY)(COOL APPROACH)(DP):

    // explanation : https://leetcode.com/problems/sliding-window-maximum/solutions/951894/c-easy-dp-o-n-explained-no-deque-required-d/?orderBy=most_votes

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
		{
			int i, j, n = nums.size(), wins;
			wins = n - k + 1;                        // # of windows
			vector<int> lft(n), rgt(n);            // to store above explained lft and rgt

			for (i = 0; i < n; i++)
			{
				lft[i] = nums[i];
				 // If it start of block, then that element is max so far in the block
				 // Else lft[i] is max so far in the block
				if (i % k !=0) 
					lft[i] = max(lft[i - 1], lft[i]);
			}

			rgt[n - 1] = nums[n - 1];
			for (i = n - 2; i >= 0; i--)
			{
				rgt[i] = nums[i];
				// same as for left, but now traversing from right
				if (i % k != (k - 1))
					rgt[i] = max(rgt[i], rgt[i + 1]);
			}

			vector<int> ans;

			for (i = 0; i < wins; i++)
				ans.push_back(max(rgt[i], lft[i + k - 1]));

			return ans;
		}

    // iii) My initial approach : (GIVES TLE)

    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> ans(n-(k-1),INT_MIN);
    //     for(int i=0;i<n;i++){
    //         for(int j=i-(k-1);j<=i;j++){
    //             if(0<=j && j<n-(k-1)){
    //                ans[j] = max(ans[j],nums[i]);
    //             }
    //         }
    //     }
    //     return ans;
    // }
