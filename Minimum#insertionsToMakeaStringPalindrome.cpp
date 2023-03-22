//    Q) Minimum Insertions to make a string Palindrome -> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

    // i) My approach : 

    // IMPORTANT POINTS:
    //    i) Reverse of a Palindrome is the string itself.
    //    ii) So if we reverse a string and then find the longest common subsequence of those, then the lcs will be a palindrome.
    //    iii) So here what I do is, find the length of lcs of given string and its reverse, then the length of string minus(-) the length of lcs gives me the count of those characters in given string, which are not having suitable character at suitable place to form a palindrome, so we have to insert these no.of characters in the suitable positions. 

    int minInsertions(string s){
        string t = s;
        reverse(t.begin(),t.end());
        int l = longestCommonSubsequence(s,t);
        int n = s.size();
        return (n-l);
    }
	
	int longestCommonSubsequence(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> tab(n+1,vector<int> (m+1));
        for(int i=0;i<n+1;i++){
            tab[i][m] = 0;
        }
        for(int j=0;j<m+1;j++){
            tab[n][j] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i] == t[j]) tab[i][j] = 1 + tab[i+1][j+1];
                else tab[i][j] = max(tab[i+1][j],tab[i][j+1]);
            }
        }
        return tab[0][0];
    }


    // ii) MY FAILED APPROACH : 


    // int minInsertions(string s) {
    //     int n = s.size();
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(0,n-1,s,n,memo);
    // }

    // int solve(int i,int j,string& s,int n,vector<vector<int>>& memo){
    //     if(i>=j){
    //         return 0;
    //     }
    //     if(memo[i][j] == -1){
    //         if(s[i] == s[j]){
    //             memo[i][j] = solve(i+1,j-1,s,n,memo);
    //         }
    //         else{
    //             if(s[i+1] == s[j] && s[i] == s[j-1]){
    //                 memo[i][j] = 1 + min(solve(i+1,j-2,s,n,memo),solve(i+2,j-1,s,n,memo));
    //             }
    //             else if(s[i+1] == s[j]){
    //                 memo[i][j] = 1 + solve(i+2,j-1,s,n,memo);
    //             }
    //             else if(s[i] == s[j-1]){
    //                 memo[i][j] = 1 + solve(i+1,j-2,s,n,memo);
    //             }
    //             else{
    //                 memo[i][j] = 2 + solve(i+1,j-1,s,n,memo);
    //             }
    //         }
    //     }
    //     return memo[i][j];
    // }