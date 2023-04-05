// Q) Maximal Rectangle -> https://leetcode.com/problems/maximal-rectangle/description/

    // Ans) 

    // i) Approach COOL problem : 

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> height(n+1);
        height[n] = -1;
        int ans = 0;
        for(int i=0;i<m;i++){
            stack<int> st;
            for(int j=0;j<n+1;j++){
                if(j < n) height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
                while(!st.empty() && height[st.top()] >= height[j]){
                    int cur = st.top();
                    st.pop();
                    ans = max(ans,height[cur]*((st.empty()) ? j : j - st.top() - 1));
                }
                st.push(j);
            }
        }
        return ans;
    }
