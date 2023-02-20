Q) Kosaraju's algorithm (No.of Strongly connected components) -> https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
 
    // Ans) 
    
    // i) Kosaraju algorithm :
    
    // Approach : The algorithm is simple, one thing to be observed is that if we start dfs on one of the node in
    // a SCC, then we can visit all the nodes in that SCC. And we can reach one SCC from another. So if we reverse all the edges
    // and then again do dfs, then we can reach all the nodes in that particular SCC but we cannot visit another SCC.
    // so this is the basic approach. We : 
    // i) First sort the nodes in the order of finishing time.
    // ii) Reverse all the edges
    // iii) Perform dfs again to find the SCC's.
	
	void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	
	void dfs3(int node,vector<int> &vis,vector<int> adjt[]){
	    vis[node] = 1;
	    for(auto it : adjt[node]){
	        if(!vis[it]){
	            dfs3(it,vis,adjt);
	        }
	    }
	}
	
	int kosaraju(int v,vector<vector<int>>& adj){
	    vector<int> vis(v,0);
	    stack<int> st;
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    vector<int> adjt[v];
	    for(int i=0;i<v;i++){
	        vis[i] = 0;
	        for(auto it : adj[i]){
	            adjt[it].push_back(i);
	        }
	    }
	    int scc = 0;
	    while(!st.empty()){
	        int node = st.top();
	        st.pop();
	        if(!vis[node]){
	            scc++;
	            dfs3(node,vis,adjt);
	        }
	    }
	    return scc;
	}