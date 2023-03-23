// Q) Wildcard Matching -> https://leetcode.com/problems/wildcard-matching/description/

    // Ans) 

    // i) My Top-down Approach :

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> memo(n,vector<int> (m,-1));
        return solve(0,0,s,p,memo);
    }

    bool solve(int i,int j,string& s,string& p,vector<vector<int>>& memo){
        int n = s.size(),m = p.size();
        if(i==n && j==m){
            return true;
        }
        else if(i==n){
            if(p[j] == '*') return solve(i,j+1,s,p,memo);
            else return false;
        }
        else if(j==m){
            return false;
        }
        if(memo[i][j] == -1){
            if(s[i] == p[j]){
                memo[i][j] = solve(i+1,j+1,s,p,memo);
            }
            else if(p[j] == '?'){
                memo[i][j] = solve(i+1,j+1,s,p,memo);
            }
            else if(p[j]=='*'){
                // bool x = solve(i+1,j+1,s,p,memo); // Actually not required
                bool y = solve(i+1,j,s,p,memo);
                bool z = solve(i,j+1,s,p,memo); // * considered as empty sequence
                // memo[i][j] = x || y || z;
                memo[i][j] = y || z;
            }
            else{
                return false;
            }
        }
        return (bool)memo[i][j];
    }