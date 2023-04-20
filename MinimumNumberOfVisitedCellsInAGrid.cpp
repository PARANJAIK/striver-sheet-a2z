 // Q) Minimum Number of visited cells in a grid -> https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

    // Ans) IN THIS QUESTION JUST UNDERSTAND THE LOGIC OF THE PROBLEM PROPERLY , BECAUSE ALL THE ACCEPTED CODES ARE ALSO GIVING WRONG ANSWER ON 1062 TEST CASE.

    //   i) Proper approach: (NO TLE)

    // NOTE : IT IS A SIMPLE PROBLEM THE KEY POINT OF THIS PROBLEM IS THAT WHEN YOU ARE AT A PARTICULAR (i,j) YOU PUSH ALL THE ELEMENTS FROM i+1 to i+grid[i][j] (say temp), and while execution of any of this element we can directly start from temp and go till i + grid[i][j]. This saves us few iterations. SO NO TLE.
 
    // int minimumVisitedCells(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     queue<pair<int, int>> qu; 
    //     qu.push({0,0});
    //     vector<int> max_i(n,0), max_j(m,0);  
    //     int steps = 0; 
    //     while(!qu.empty()) {
    //         steps++;
    //         int sz = qu.size();
    //         while(sz--) {
    //             auto top = qu.front();
    //             qu.pop();
    //             int i = top.first;
    //             int j = top.second; 
    //             if(i == n-1 && j == m-1) return steps; 
    //             for(int k = max(i, max_j[j])+1; k <= min(n-1, grid[i][j]+i); k++) {
    //                 if(k == n-1 && j == m-1) return steps+1;
    //                 qu.push({k,j});
    //             }
    //             for(int k = max(j, max_i[i])+1; k <= min(m-1, grid[i][j]+j); k++) {
    //                 if(i == n-1 && k == m-1) return steps+1;
    //                 qu.push({i,k}); 
    //             }
    //             max_i[i] = max(max_i[i], grid[i][j]+j);
    //             max_j[j] = max(max_j[j], grid[i][j]+i); 
    //         }
    //     }
    //     return -1; 
    // }

    // int minimumVisitedCells(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size(), steps = 0;
    //     vector<int> max_i(n,0), max_j(m,0);
    //     queue<pair<int, int>> q;
    //     q.push({0, 0});
    //     // vector<pair<int, int>> q{{0, 0}}, q1;
    //     while (!q.empty()) {
    //         ++steps;
    //         int sz = q.size();
    //         while (sz--) {
    //         // for (auto [i, j] : q) {
    //             auto [i, j] = q.front(); q.pop();
    //             if (i == m - 1 && j == n - 1) return steps;
    //             for (int k = max(max_i[j], i) + 1; k < m && k - i <= grid[i][j]; ++k)
    //                 q.push({k, j});
    //             for (int k = max(max_j[i], j) + 1; k < n && k - j <= grid[i][j]; ++k)
    //                 q.push({i, k});
    //             max_i[j] = max(max_i[j], i + grid[i][j]);
    //             max_j[i] = max(max_j[i], j + grid[i][j]);
    //         // }
    //         }
    //         // swap(q, q1);
    //         // q1.clear();
    //     }
    //     return -1;
    // }


  
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        dis[0][0]=0;
        
        while(!q.empty()) {

            auto front = q.front();
            q.pop();
            int x=front.first, y=front.second;

            int num = grid[x][y];
            if(x==n-1 && y==m-1) return dis[n-1][m-1]+1;
            for(int j=min(y+num, m-1); j>=y+1; j--) {
                if(!vis[x][j]) {
                    dis[x][j] = min(dis[x][j], dis[x][y]+1);
                    q.push({x, j});
                    vis[x][j] = 1;
                }
                
            }
            for(int i=min(x+num, n-1); i>=x+1; i--) {
                if(!vis[i][y]) {
                    dis[i][y] = min(dis[i][y], dis[x][y]+1);
                    q.push({i, y});
                    vis[i][y] = 1;
                }   
            }

        }

        return dis[n-1][m-1] == INT_MAX ? -1 : dis[n-1][m-1]+1;
    }



//    ii) My BFS approach : (FAILED DUE TO TLE)

//    int minimumVisitedCells(vector<vector<int>>& grid){
//        int m = grid.size(),n = grid[0].size();
//        vector<vector<int>> vis(m,vector<int> (n,0));
//        queue<vector<int>> q;
//        q.push({0,0,1});
//        vis[0][0] = 1;
//        int ans = -1;
//        while(!q.empty()){
//            auto cell = q.front();q.pop();
//            int i = cell[0],j = cell[1],d = cell[2];
//            if(i==m-1 && j==n-1){
//                ans = d;
//                break;
//            }
//            for(int x = i+1;x <= i + grid[i][j] && x < m;x++){
//                if(vis[x][j] == 1) continue;
//                q.push({x,j,d+1});
//                vis[x][j] = 1;
//            }
//            for(int y = j+1;y <= j + grid[i][j] && y < n;y++){
//                if(vis[i][y] == 1) continue;
//                q.push({i,y,d+1});
//                vis[i][y] = 1;
//            }
//         }
//         return ans;
//    }

    //   iii) My 1st DP approach :(FAILED DUE TO TLE)

//     int minimumVisitedCells(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<int> memo(m*n+1,-1);
//         int ans = solve(0,grid,memo);
//         return (ans >= 1e9) ? -1 : ans;
//     }
    
//     int solve(int index,vector<vector<int>>& grid,vector<int>& memo){
//         int m = grid.size();
//         int n = grid[0].size();
//         if(index == m*n - 1){
//             return 1;
//         }
//         if(memo[index] != -1) return memo[index];
//         int ans = 1e9;
//         int i = index/n;
//         int j = index%n;
//         int k = grid[i][j];
//         for(int x = j+1;x <= j+k && x < n;x++){
//             ans = min(ans,solve(i*n + x,grid,memo));
//         }
//         for(int x = i+1;x <= i+k && x < m;x++){
//             ans = min(ans,solve(x*n + j,grid,memo));
//         }
//         return memo[index] = 1 + ans;
//     }

    // iv) My 2nd DP approach : (FAILED DUE TO TLE)
    
    // int minimumVisitedCells(vector<vector<int>>& grid){
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<int> memo(m*n+1,-1);
    //     int ans = solve(m*n-1,grid,memo);
    //     return (ans >= 1e9) ? -1 : ans;
    // }

    // int solve(int index,vector<vector<int>>& grid,vector<int>& memo){
    //     if(index == 0){
    //         return 1;
    //     }
    //     if(memo[index] != -1) return memo[index];
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int x = index/n;
    //     int y = index%n;
    //     int ans = 1e9;
    //     for(int i=0;i<y;i++){
    //         int k = y - i;
    //         if(k <= grid[x][i]){
    //             ans = min(ans,solve(x*n + i,grid,memo));
    //         }
    //     }
    //     for(int i=0;i<x;i++){
    //         int k = x - i;
    //         if(k <= grid[i][y]){
    //             ans = min(ans,solve(i*n + y,grid,memo));
    //         }
    //     }
    //     return memo[index] = 1 + ans;
    // }
