//  Q) Minimize the maximum difference of pairs : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

    // Ans) 

    // i) Binary search approach : 

        int minimizeMax(vector<int>& A, int p) {
        sort(A.begin(), A.end());
        int n = A.size(), left = 0, right = A[n - 1] - A[0];
        while (left < right) {
            int mid = (left + right) / 2, k = 0;
            for (int i = 1; i < n && k < p; ++i) {
                if (A[i] - A[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

  
//   ii) My initial DP approach : (GIVES TLE ON LAST 5 TEST CASES):

//     int minimizeMax(vector<int>& nums, int p) {
//         int n = nums.size();
//         vector<vector<int>> memo(n,vector<int> (p+1,-1));
//         sort(nums.begin(),nums.end());
//         return solve(0,p,nums,memo);
//     }
    
//     int solve(int index,int p,vector<int>& nums,vector<vector<int>>& memo){
//         int n = nums.size();
//         if(p == 0){
//             return 0;
//         }
//         if(p > (n-index)/2 || index == n){
//             return 1e9;
//         }
//         if(memo[index][p] != -1) return memo[index][p];
//         // consider
//         int diff1 = max(nums[index+1]-nums[index],solve(index+2,p-1,nums,memo));
//         // no consider
//         int diff2 = solve(index+1,p,nums,memo);
//         return memo[index][p] = min(diff1,diff2);
//     }

    // iii) My 2nd approach : (I really hope that it should work, but dont know what is the problem)

    //  struct comp {
    //  bool operator()(
    //     const pair<int, int>& a,
    //     const pair<int, int>& b)
    // {
    //     if(a.first != b.first) return a.first > b.first;
    //     else return a.second < b.second;
    // }
    // };
      
    
    //   int minimizeMax(vector<int>& nums,int p){
    //       int n = nums.size();
    //       priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    //       unordered_map<int,int> m;
    //       for(int i=0;i<n;i++){
    //           m[nums[i]]++;
    //       }
    //       for(auto pa : m){
    //           pq.push({pa.second,pa.first});
    //       }
    //       int ans = 0;
    //       while(p > 0){
    //           pair<int,int> pa = pq.top();
    //           pq.pop();
    //           if(pa.first > 1){
    //               p = p - (pa.first/2);
    //               if(p == 0) break;
    //               pa.first = pa.first%2;
    //               if(pa.first > 0) pq.push({pa.first,pa.second});
    //           }
    //           else{
    //               pair<int,int> qa = pq.top();
    //               pq.pop();
    //               p--;
    //               ans = max(ans,abs(qa.second - pa.second));
    //               if(p == 0) break;
    //           }
    //       }
    //       return ans;
    //   }
