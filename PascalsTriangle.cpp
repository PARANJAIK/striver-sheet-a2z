// Q) Pascal's Triangle -> https://leetcode.com/problems/pascals-triangle/description/
                        //  -> https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9 

    // Ans)

    // i) My approach : 

    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> ans;
    //     vector<int> row;
    //     row.push_back(1);
    //     while(numRows--){
    //         ans.push_back(row);
    //         row.push_back(0);
    //         vector<int> temp;
    //         temp.push_back(1);
    //         for(int i=1;i<row.size();i++){
    //             temp.push_back(row[i]+row[i-1]);
    //         }
    //         row = temp;
    //     }
    //     return ans; 
    // }

    // ii) Stirver's Approach : 

    vector<vector<int>> generate(int numRows){
        vector<vector<int>> r(numRows);
        for(int i=0;i<numRows;i++){
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
            for(int j=1;j<i;j++){
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }
        return r;
    }