// Q) Scramble String -> https://www.interviewbit.com/problems/scramble-string/

// Ans) 

// i) My Proper approach : 

bool solve(const string& s,const string& t,int i1,int j1,int i2,int j2,vector<vector<vector<vector<int>>>>& memo){
    if(i1 > j1 || i2 > j2) return false;
    if(i1 == j1){
        if(s[i1] == t[i2]) return true;
        else return false;
    }
    if(memo[i1][j1][i2][j2] != -1) return memo[i1][j1][i2][j2];
    // checking if they are equal
    string temp1 = s.substr(i1,j1-i1+1);
    string temp2 = t.substr(i2,j2-i2+1);
    // if equal
    if(temp1 == temp2){
        return memo[i1][j1][i2][j2] = true;
    }
    // if not equal
    int x = j1-i1+1;
    for(int k=0;k<x-1;k++){
        // without scrambling
        int one = solve(s,t,i1,i1+k,i2,i2+k,memo) && solve(s,t,i1+k+1,j1,i2+k+1,j2,memo);
        // with scrambling
        int two = solve(s,t,i1,i1+k,j2-k,j2,memo) && solve(s,t,i1+k+1,j1,i2,j2-k-1,memo);
        if(one || two){
            return memo[i1][j1][i2][j2] = true;
        }
    }
    return memo[i1][j1][i2][j2] = false;
}

int Solution::isScramble(const string s, const string t) {
    if(s.size() != t.size()) return 0;
    if(s.empty() && t.empty()) return 1;
    int n = s.size();
    vector<vector<vector<vector<int>>>> memo(n,vector<vector<vector<int>>> (n,vector<vector<int>> (n,vector<int> (n,-1))));
    return solve(s,t,0,n-1,0,n-1,memo);
}
