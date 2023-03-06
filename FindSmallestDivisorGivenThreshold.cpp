//    Q) Find the smallest divisor give a threshold -> https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

//    Ans) NOTE : We can even do a linear search but binary search is optimal.

//    i) My approach : Do a simple Binary search using a predicate function.

    bool check(vector<int>& nums,int mid,int threshold){
        int ans = 0;
        for(auto num : nums){
            ans += ceil(num/(float)mid);
        }
        if(ans <= threshold) return true;
        else return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1,high = *max_element(nums.begin(),nums.end());
        while(high-low>1){
            int mid = (low+high)>>1;
            bool x = check(nums,mid,threshold);
            if(x){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(check(nums,low,threshold)) return low;
        else return high;
    }