 // Q) Assign Cookies -> https://leetcode.com/problems/assign-cookies/description/

    // Ans) 

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int m = g.size(),n = s.size();
        while(i < m && j < n){
            if(s[j] >= g[i]){
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        return i;
    }