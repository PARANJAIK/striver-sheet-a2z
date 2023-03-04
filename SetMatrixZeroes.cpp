// Q) Set Matrix Zeroes -> https://leetcode.com/problems/set-matrix-zeroes/description/

    // Ans) 

    // i) My approach : 

    // Used O(M+N) space to store the rows and columns which have to be set to zeros.

    // void setZeroes(vector<vector<int>>& matrix) {
    //     set<int> rows,cols;
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(matrix[i][j]==0){
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }
    //     for(auto row : rows){
    //         for(int j=0;j<n;j++){
    //             matrix[row][j] = 0;
    //         }
    //     }
    //     for(auto col : cols){
    //         for(int i=0;i<m;i++){
    //             matrix[i][col] = 0;
    //         }
    //     }
    //     return;
    // }

    // ii) Striver's approach : 

    // used O(1) space, the dummy rows and columns arrays are not used seperately. The first row and first column of the 2D matrix are used to store the rows and columns which are to made zeroes.

    void setZeroes(vector<vector<int>>& matrix){
        int col0 = 1, rows = matrix.size() , cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            if(matrix[i][0] == 0) col0 = 0;
            for(int j=1;j<cols;j++){
                if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i = rows-1;i>=0;i--){
            for(int j = cols-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
    }