 // Q) check knight tour configuration : https://leetcode.com/problems/check-knight-tour-configuration/description/

    // Ans) 

    // i) My approach :

    // bool checkValidGrid(vector<vector<int>>& grid) {
    //     int n = grid[0].size();
    //     if(grid[0][0] != 0) return false;
    //     pair<int,int> p[8] = {{-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1}};
    //     int index = 0;
    //     int count = 1;
    //     while(count <= n*n-1){
    //         bool found = false;
    //         for(auto pa : p){
    //             int x = index/n + pa.first;
    //             int y = index%n + pa.second;
    //             if(0<=x && x<n && 0<=y && y<n && grid[x][y] == count){
    //                 count++;
    //                 found = true;
    //                 index = x*n + y;
    //                 break;
    //             }
    //         }
    //         if(found) continue;
    //         return false;
    //     }
    //     return true;
    // }

    // ii) external approach : (best till now)

     bool checkValidGrid(vector<vector<int>>& g) {
    if (g[0][0] != 0) // this is silly ;p
        return false;
    array<int, 2> m[7 * 7] = {};
    for (int x = 0; x < g.size(); ++x)
        for (int y = 0; y < g.size(); ++y)
            m[g[x][y]] = {x, y};
    for (int i = 1; i < g.size() * g.size(); ++i)
        if (abs((m[i][0] - m[i - 1][0]) * (m[i][1] - m[i - 1][1])) != 2)
            return false;
    return true;
}

    // iii) external approach : 

    // bool checkValidGrid(vector<vector<int>>& grid) {

        
    //     if(grid[0][0] != 0)return false;
        
        
    //     int n = grid.size();
    //     int m = grid[0].size();
        
    //     vector<pair<int, pair<int,int>> >v;
        
    //     for(int i=0;i<n;i++) {
    //         for(int j=0;j<m;j++) {
    //             v.push_back({grid[i][j], {i, j}});
    //         }
    //     }
         
    //     sort(v.begin(), v.end());
        
    //     for(int i=0;i<v.size()-1;i++) {
    //         int dy = abs(v[i].second.second - v[i+1].second.second);
    //         int dx = abs(v[i].second.first - v[i+1].second.first);
        
    //         if( (dx == 1 && dy == 2) || (dx == 2 && dy == 1) ) continue;
            
    //         return false;
    //     }
                            
    //     return true;
    
    // }

    // iv) external approach : 

    // bool checkValidGrid(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     queue<pair<int,int>> q;
    //     int dx[8]={-2,-2,2,2,-1,1,-1,1};
    //   int dy[8]={-1,1,-1,1,-2,-2,2,2};
    //     int count=1;
    //     vector<vector<int>> vis(n,vector<int>(n,-1));
    //     q.push({0,0});
    //     vis[0][0]=1;
    //     while(!q.empty()){
    //         int s=q.size();
    //         while(s--){
    //             auto it=q.front();
    //             q.pop();
    //             int row=it.first;
    //             int col=it.second;
    //             for(int i=0;i<8;i++){
    //                 int r=row+dx[i];
    //                 int c=col+dy[i];
    //                 if(r>=0&&r<n&&c>=0&&c<n&&vis[r][c]==-1){
    //                     if(grid[r][c]==count){
    //                         // cout<<"r: "<<r<<" "<<"c: "<<c<<endl;
    //                         if(grid[r][c]==(n*n-1))
    //                         return true;
    //                         count++;
    //                         q.push({r,c});
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }
