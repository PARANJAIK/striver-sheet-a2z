// Q) Minimum Reverse Operations : https://leetcode.com/problems/minimum-reverse-operations/description/

    // NOTE : IN THIS PROBLEM THE KEY POINT IS THAT, IN MY FIRST APPROACH IT GIVES TLE BECAUSE I AM TRAVERSING ALL REACHABLE ELEMENTS BY A CURRENT INDEX ALL THE TIME THOUGH THEY ARE ALREADY COMPUTED, SO THE BETTER APPROACH CAN ACTUALLY BE LIKE CARRY EVEN AND ODD INDICES SETS AND DYNAMICALLY ERASE ALL THOSE INDICES WHICH ARE COMPUTED.

    // i) My first approach : (GIVES TLE)

    //  vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    //     vector<int> ans(n,1e9);
    //     ans[p] = 0;
    //     for(int i=0;i<banned.size();i++){
    //         ans[banned[i]] = -1;
    //     }
    //     queue<int> q;
    //     q.push(p);
    //     while(!q.empty()){
    //         int index = q.front();
    //         q.pop();
    //         int l1 = max(0,index-(k-1));
    //         int l2 = min(n-1,index+(k-1)) - (k-1);
    //         for(int l = l1;l<=l2;l++){
    //             int effect = 2*l + (k-1) - index;
    //             if(ans[effect] == -1) continue;
    //             if(ans[index] + 1 < ans[effect]){
    //                 ans[effect] = ans[index] + 1;
    //                 q.push(effect);
    //             } 
    //         } 
    //     }
    //     for(int i=0;i<n;i++){
    //         if(ans[i] == 1e9) ans[i] = -1;
    //     }
    //     return ans;
    // }

    // ii) My 2nd approach : 

    // vector<int> minReverseOperations(int n,int p,vector<int>& banned,int k){
    //     vector<int> ans(n,1e9);
    //     ans[p] = 0;
    //     set<int> s[2];
    //     for(int i=0;i<n;i++){
    //         s[i&1].insert(i);
    //     }
    //     for(int i=0;i<banned.size();i++){
    //         ans[banned[i]] = -1;
    //         s[banned[i] & 1].erase(banned[i]);
    //     }
    //     queue<int> q;
    //     q.push(p);
    //     s[p & 1].erase(p);
    //     while(!q.empty()){
    //         int index = q.front();
    //         q.pop();
    //         int l1 = max(0,index-(k-1));
    //         int l2 = min(n-1,index+(k-1)) - (k-1);
    //         int left = 2*l1 + (k-1) - index;
    //         int right = 2*l2 + (k-1) - index;
    //         auto start = s[left & 1].lower_bound(left);
    //         auto end = s[left & 1].upper_bound(right);
    //         for(auto it = start;it != end;it++){
    //             if(ans[index] + 1 < ans[*it]){
    //                 ans[*it] = ans[index] + 1;
    //                 q.push(*it);
    //             }
    //         }
    //         s[left & 1].erase(start,end);
    //     }
    //     for(auto it : s[0]){
    //         ans[it] = -1;
    //     }
    //     for(auto it : s[1]){
    //         ans[it] = -1;
    //     }
    //     return ans;
    // }

    // iii) More better implementation : 

    // // Returns a range that pivot can be possibly at after reversing a subarray with length k.
    inline pair<int, int> getRange(int n, int pivot, int k) {
		// Left most subarray containing pivot
        int l1 = max(0, pivot - k + 1);
        int r1 = l1 + k - 1;
		
		// Right most subarray containing pivot
        int r2 = min(n - 1, pivot + k - 1);
        int l2 = r2 - k + 1;
		
		int left = r1 - (pivot - l1);
        int right = l2 + (r2 - pivot);
        return {left, right};
    }
    
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> bans(banned.begin(), banned.end());
        vector<int> ans(n, -1);
        // BST to store all nodes not visited yet.
        set<int> s[2];

        ans[p] = 0;
        // Put all available postions in BST, split by parity
        for (int i = 0; i < n; i ++)
            if (i != p && bans.find(i) == bans.end())
                s[i & 1].insert(i);
        
        // Queue for BFS floodfill.
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int pivot = q.front();
            q.pop();
            auto range = getRange(n, pivot, k);

            // for current pivot, check if it will visit even positions or odd positions. 
            int o = (k % 2 == 0) ? (1 - pivot & 1) : (pivot & 1);
            //int o = (k & 1) ^ (pivot & 1) ^ 1;

            // Find all reachable indexes range on the tree.
            auto bg = s[o].lower_bound(range.first);
            auto ed = s[o].upper_bound(range.second);

            // Visit reachable indexes and update answer.
            for (auto it = bg; it != ed; it ++) {
                ans[*it] = ans[pivot] + 1;
                q.push(*it);
            }

            // Remove visited indexes from tree.
            s[o].erase(bg, ed);
        }

        return ans;
    }
