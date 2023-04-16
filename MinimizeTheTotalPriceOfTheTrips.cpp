// Q) Minimize the Total Price of the trips -> https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/

    // Ans) 

    // i) My approach : 

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> count(n,0);
        for(auto t : trips){
            vector<int> path;
            paths(t[0],t[1],-1,path,adj,count);
        }
        vector<vector<int>> memo(n,vector<int> (2,-1));
        return solve(0,0,-1,adj,count,price,memo);
    }
    
    void paths(int node,int end,int parent,vector<int>& path,vector<vector<int>>& adj,vector<int>& count){
        path.push_back(node);
        if(node == end){
            for(auto x : path){
                count[x]++;
            }
            path.pop_back();
            return;
        }
        for(auto x : adj[node]){
            if(x != parent) paths(x,end,node,path,adj,count);
        }
        path.pop_back();
        return;
    }
    
    int solve(int node,int parenthalved,int parent,vector<vector<int>>& adj,vector<int>& count,vector<int>& price,vector<vector<int>>& memo){
        if(memo[node][parenthalved] != -1) return memo[node][parenthalved];
        // not halving it
        int nothalf = count[node]*price[node];
        int yeshalf = (parenthalved) ? INT_MAX : count[node]*price[node]/2;
        for(auto x : adj[node]){
            if(x == parent) continue;
            nothalf += solve(x,0,node,adj,count,price,memo);
            if(parenthalved == 0) yeshalf += solve(x,1,node,adj,count,price,memo);
        }
        return memo[node][parenthalved] = min(nothalf,yeshalf);
    }
