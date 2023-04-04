// Q) Next Greater Element II -> https://leetcode.com/problems/next-greater-element-ii/description/

    // Ans) Circular array thing :

    vector<int> nextGreaterElements(vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i%n]){
                st.pop();
            }
            if(st.empty()) ans[i%n] = -1;
            else ans[i%n] = st.top();
            st.push(nums2[i%n]);
        }
        return ans;
    }