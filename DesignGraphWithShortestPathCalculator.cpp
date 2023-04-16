// Q) Design Graph with Shortest Path Calculator : 

// Ans)

// i) My approach : Floyd-warshall algorithm

// Alternate approach:  dijikstra in shortest path () function

// class Graph {
// public:
//     vector<vector<int>> dist;
    
//     Graph(int n, vector<vector<int>>& edges) {
//         dist.resize(n,vector<int> (n,1e9));
//         for(int i=0;i<n;i++){
//             dist[i][i] = 0;
//         }
//         for(auto edge : edges){
//             dist[edge[0]][edge[1]] = edge[2];
//         }
//         for(int k=0;k<n;k++){
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<n;j++){
//                     dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
    
//     void addEdge(vector<int> edge) {
//         int n = dist.size();
//         if(edge[2] < dist[edge[0]][edge[1]]){
//             dist[edge[0]][edge[1]] = edge[2];
//             for(int k=0;k<2;k++){
//                 for(int i=0;i<n;i++){
//                   for(int j=0;j<n;j++){
//                     dist[i][j] = min(dist[i][j],dist[i][edge[k]] + dist[edge[k]][j]);
//                   }
//                 }
//             }
//         }
//     }
    
//     int shortestPath(int node1, int node2) {
//         return (dist[node1][node2] == 1e9) ? -1 : dist[node1][node2]; 
//     }
// };

// ii) Improved implementation of my approach : 

class Graph {
public:
    vector<vector<int>> am;
    Graph(int n, vector<vector<int>>& edges) {
        am = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &e : edges)
            am[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            am[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
    }
    void addEdge(const vector<int> &e) {
        for (int i = 0; i < am.size(); ++i)
            for (int j = 0; j < am.size(); ++j)
                am[i][j] = min(am[i][j], am[i][e[0]] + am[e[1]][j] + e[2]);
    }
    int shortestPath(int n1, int n2) {
        return am[n1][n2] == 1e9 ? -1 : am[n1][n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
