 // Q) Sum of Subarray Minimums -> https://leetcode.com/problems/sum-of-subarray-minimums/description/

    // Ans) 

    // i) Approach : The approach is we need to find the number of subarrays in which the current element will be the minimum. For that we find the indices of previous less element(PLE) and next less element(NLE) of all the elements.

    // Explanation : https://leetcode.com/problems/sum-of-subarray-minimums/solutions/178876/stack-solution-with-very-detailed-explanation-step-by-step/?orderBy=most_votes

    // NOTE : WE CAN FIND NLE EVEN BY FINDING PLE BY REVERSE ITERATING THE ARRAY.
    // NOTE : BUT IN THIS QUESTION BOTH PLE AND NLE ARE FOUND IN A ONE SINGLE PASS.

    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ple(n,-1),nle(n,n);   // This initialisation takes care of st.empty() case for ple and no next less element case for nle.
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                nle[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) ple[i] = st.top();
            st.push(i); 
        }
        int M = 1e9 + 7;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = (1LL*ans + (1LL*arr[i]*(i-ple[i])*(nle[i]-i))%M)%M;
        }
        return ans;
    }