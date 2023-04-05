 // Q) Sum Of Subarray ranges -> https://leetcode.com/problems/sum-of-subarray-ranges/description/

    // Ans) 

    // i) My approach : 

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ple(n,-1),nle(n,n);
        vector<int> pge(n,-1),nge(n,n);
        stack<int> st;
        stack<int> stt;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                nle[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) ple[i] = st.top();
            st.push(i);
            while(!stt.empty() && nums[stt.top()] <= nums[i]){
                nge[stt.top()] = i;
                stt.pop();
            } 
            if(!stt.empty()) pge[i] = stt.top();
            stt.push(i);
        }
        long long int ans = 0;
        for(int i=0;i<n;i++){
            ans += (1LL*nums[i]*(nge[i]-i)*(i-pge[i])) - (1LL*nums[i]*(nle[i]-i)*(i-ple[i]));
        }
        return ans;
    }

    // ii) Tried to improve, I hoped it did, but realised it didn't, dont know why ?

    // long long subArrayRanges(vector<int>& nums){
    //     int n = nums.size();
    //     stack<int> st;
    //     stack<int> stt;
    //     long long int ans = 0;
    //     for(int i=0;i<n;i++){
    //         while(!st.empty() && nums[st.top()] >= nums[i]){
    //             int cur = st.top();
    //             st.pop();
    //             int pleindex = (st.empty()) ? -1 : st.top();
    //             ans -= (1LL*nums[cur]*(i-cur)*(cur-pleindex));
    //         }
    //         st.push(i);
    //         while(!stt.empty() && nums[stt.top()] <= nums[i]){
    //             int cur = stt.top();
    //             stt.pop();
    //             int pgeindex = (stt.empty()) ? -1 : stt.top();
    //             ans += (1LL*nums[cur]*(i-cur)*(cur-pgeindex));
    //         }
    //         stt.push(i);
    //     }
    //     while(!st.empty()){
    //         int cur = st.top();
    //         st.pop();
    //         int pleindex = (st.empty()) ? -1 : st.top();
    //         ans -= (1LL*nums[cur]*(n-cur)*(cur-pleindex));
    //     }
    //     while(!stt.empty()){
    //         int cur = stt.top();
    //         stt.pop();
    //         int pgeindex = (stt.empty()) ? -1 : stt.top();
    //         ans += (1LL*nums[cur]*(n-cur)*(cur-pgeindex));
    //     }
    //     return ans;
    // }
