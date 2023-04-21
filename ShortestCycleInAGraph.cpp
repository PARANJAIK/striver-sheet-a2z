// Q) Shortest Cycle in a Graph -> https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

    // Ans) 

    // NOTE :  SINCE WE ARE IMPLEMENTING THE BFS ON ALL ELEMENTS AS THE STARTING POINT IRRESPECTIVE OF THEY ARE VISITED WHEN OTHERS ARE STARTING POINTS, WE WILL DEFINITELY GET THE SHORTEST CYCLE.

    // i) My initial approach (MOST OPTIMAL IN MY VIEW) : (BUT FAILING IN LAST 6 TEST CASES, I KNOW WHY BUT NOT ABLE TO RESOLVE IT)

    // int findShortestCycle(int n, vector<vector<int>>& edges) { 
    //     vector<vector<int>> adj(n);
    //     for(int i=0;i<edges.size();i++){
    //         adj[edges[i][0]].push_back(edges[i][1]);
    //         adj[edges[i][1]].push_back(edges[i][0]);
    //     }
    //     vector<int> level(n,-1);
    //     vector<int> ld(n,-1);
    //     vector<int> parent(n,-1);
    //     queue<int> q;
    //     int ans = INT_MAX;
    //     for(int i=0;i<n;i++){
    //         if(level[i] == -1){
    //             q.push(i);
    //             level[i] = 1;
    //             ld[i] = i;
    //             parent[i] = i;
    //             while(!q.empty()){
    //                 int node = q.front();
    //                 q.pop();
    //                 vector<int> unvis;
    //                 for(auto child : adj[node]){
    //                     if(child == parent[node]) continue;
    //                     if(level[child] == -1){
    //                        parent[child] = node;
    //                        unvis.push_back(child);   
    //                        level[child] = level[node] + 1;
    //                        q.push(child);
    //                     }
    //                     else{
    //                         // cylce detected
    //                         int ldc = ld[child],ldn = ld[node];
    //                         while(ldc != ldn){
    //                             if(level[ldc] > level[ldn]){
    //                                 ldc = ld[ldc];
    //                             }
    //                             // else if(level[ldc] == level[ldn] && ld[ldc] == ld[ldn]){
    //                                 // break;
    //                             // }
    //                             else{
    //                                 ldn = ld[ldn];
    //                             }
    //                         }
    //                         ans = min(ans,level[node] - level[ldc] + level[child] - level[ldn] + 1);
    //                     }
    //                 }
    //                 if(unvis.size() > 1){
    //                     for(auto x : unvis){
    //                         ld[x] = node;
    //                     }
    //                 }
    //                 else{
    //                     for(auto x : unvis){
    //                         ld[x] = ld[node];
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return (ans == INT_MAX) ? -1 : ans;
    // }

    // ii) Proper working approach : 
    
    int ans = INT_MAX;

    void bfs(int src,vector<int> adj[],int n){
            vector<int> distance(n,(1e9));
            vector<int> parent(n, -1);
            
            queue<int> q;
            distance[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto neigh : adj[node]) {
                    if (distance[neigh] == (int)(1e9)) {
                        distance[neigh] = 1 + distance[node];
                        parent[neigh] = node;
                        q.push(neigh);
                }
                else if (parent[node] != neigh && parent[neigh] != node)
                    ans = min(ans, distance[neigh] + distance[node] + 1);
                }
            }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      
        for (int i = 0; i < n; i++)
        {
            bfs(i,adj,n);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
