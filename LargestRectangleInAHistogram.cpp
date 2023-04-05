 // Q) Largest Rectangle in Histogram -> https://leetcode.com/problems/largest-rectangle-in-histogram/description/

    // Ans) 

    // i) My initial approach : (COOL BUT WE CAN MAKE IT BETTER BY NOT USING THE NLE AND PLE VECTORS, AND EVEN BY NOT USING THE 2ND FOR LOOP SINCE WE COMPUTE OUR ANS IN THE 1ST FOR LOOP ONLY.)

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     stack<int> st;
    //     vector<int> nle(n,n),ple(n,-1);
    //     for(int i=0;i<n;i++){
    //         while(!st.empty() && heights[st.top()] >= heights[i]){
    //             nle[st.top()] = i;
    //             st.pop();
    //         }
    //         if(!st.empty()) ple[i] = st.top();
    //         st.push(i);
    //     }
    //     int ans = INT_MIN;
    //     for(int i=0;i<n;i++){
    //         ans = max(ans,heights[i]*((nle[i]-i) + (i-ple[i]) - 1));
    //     }
    //     return ans;
    // }

    // ii) My improved COOL Approach : 

    int largestRectangleArea(vector<int>& heights){
        heights.push_back(0); // this is done to make sure that all the heights bars are computed for largest area rectangle.
        int n = heights.size();
        stack<int> st;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int cur = st.top();
                st.pop();
                int pleindex = (st.empty()) ? -1 : st.top();
                int nleindex = i;
                ans = max(ans,heights[cur]*(nleindex-pleindex-1));
            }
            st.push(i);
        }
        return ans;
    }
