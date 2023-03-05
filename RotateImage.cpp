//    Q) Rotate Image -> https://leetcode.com/problems/rotate-image/description/

    //  Ans) 

    //  i) My approach : Rotate the boundaries. And gradually decrease the boundary size.

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int th = 0;
        for(int m = n;m>=2;m-=2){
            int rowstart = th,colstart = th;
            int rowend = th + (m-1),colend = th + (m-1);
            for(int i = 0;i<m-1;i++){
                int temp,x = matrix[rowstart][colstart+i];
                // Right side
                temp = matrix[rowstart+i][colend];
                matrix[rowstart+i][colend] = x;
                x = temp;
                // Bottom side
                temp = matrix[rowend][colend-i];
                matrix[rowend][colend-i] = x;
                x = temp;
                // Left Side
                temp = matrix[rowend-i][colstart];
                matrix[rowend-i][colstart] = x;
                x = temp;
                // Top side
                matrix[rowstart][colstart+i] = x;
            }
            th++;
        }
    }

    // ii) Striver's approach : Take Transpose of the matrix followed by reversing each and every row of the matrix.

    // void rotate(vector<vector<int>>& m){
    //     int n = m.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             swap(m[i][j],m[j][i]);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         reverse(m[i].begin(),m[i].end());
    //     }
    // }    