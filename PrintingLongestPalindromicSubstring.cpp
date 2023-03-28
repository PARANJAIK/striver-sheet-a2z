// Q) Printing Longest Palindromic Substring :

string longestPalindrome(string s){
        int n = s.size();
        vector<vector<string>> memo(n,vector<string> (n,"-1"));
        return solve(0,n-1,s,memo);
    }

    string solve(int i,int j,string& s,vector<vector<string>>& memo){
        if(i >= j){
            string temp = "";
            if(i > j) return temp;
            temp += s[i];
            return temp;
        }
        if(memo[i][j] == "-1"){
            string one = solve(i,j-1,s,memo);
            string two = solve(i+1,j,s,memo);
            string ans = (one.size() > two.size()) ? one : two;
            if(s[i] == s[j]){
                string x = solve(i+1,j-1,s,memo);
                if(x.size() + 2 > ans.size()) ans = s[i] + x + s[i];
            }
            memo[i][j] = ans;
        }
        return memo[i][j];
    }