// Q) Spiral Matrix -> https://leetcode.com/problems/spiral-matrix/description/

    // Ans) 

    // i) My approach : 

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int th = 0;
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int th=0;th<=(n-1)/2;th++){
            if(th>(m-1)/2) break;
            int rowstart = th,colstart = th;
            int rowend = th + m - 2*th - 1;
            int colend = th + n - 2*th - 1;
            int i=rowstart,j=colstart;
            if(rowstart==rowend && colstart==colend){
                ans.push_back(matrix[rowstart][colstart]);
                continue;
            }
            while(j<colend){
               ans.push_back(matrix[i][j]);
               j++;
            }
            while(i<rowend){
                ans.push_back(matrix[i][j]);
                i++;
            }
            while(rowstart!=rowend && j>colstart){
                ans.push_back(matrix[i][j]);
                j--;
            }
            while(colstart!=colend && i>rowstart){
                ans.push_back(matrix[i][j]);
                i--;
            }
            if(rowstart==rowend || colstart==colend) ans.push_back(matrix[rowend][colend]);
        }
        return ans;
    }