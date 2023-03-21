// Use the bottom up approach and give the tabulation array as input

// Reference youtube link -> https://www.youtube.com/watch?v=-zI4mrF2Pb4

string returnlcs(vector<vector<int>>& tab,string& a,string& b){
    int n = tab.size() -1;
    int m = tab[0].size() -1;
    int i=0,j=0;
    string ans;
    while(i<n && j<m){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else{
            if(tab[i+1][j] > tab[i][j+1]){
                i++;
            }
            else{
                j++;
            }
        }
    }
    return ans;
}