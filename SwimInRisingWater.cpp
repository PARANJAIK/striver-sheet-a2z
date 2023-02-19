// Q) Swim in Rising Water -> https://leetcode.com/problems/swim-in-rising-water/description/

    // Ans) i) My approach : 

    int swimInWater(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        vector<int> vis(n*n,0);
        pair<int,int> p[4] = {{-1,0},{0,-1},{1,0},{0,1}};
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({grid[0][0],0});
        while(!pq.empty()){
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if(vis[index]) continue;
            for(int i=0;i<4;i++){
                int x = index/n + p[i].first;
                int y = index%n + p[i].second;
                if(0<=x && x<n && 0<=y && y<n && !vis[x*n + y]){
                    pq.push({grid[x][y],x*n + y});
                }
            }
            if(val > ans) ans = val;
            vis[index] = 1;
            if(index == n*n - 1) break;
        }
        return ans;
    }