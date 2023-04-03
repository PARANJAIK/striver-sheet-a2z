 // Q) Valid Parenthesis String -> https://leetcode.com/problems/valid-parenthesis-string/description/

    // Ans)

    // i) Without Using recursion and DP : (COOL APPROACH) : 

    // Explanation -> https://leetcode.com/problems/valid-parenthesis-string/solutions/302732/c-o-s-time-o-1-space-one-pass-with-explanation/?orderBy=most_votes

    // CODE: 

    // beats 100%

    bool checkValidString(string s){
        int n = s.size();
        int mindiff = 0,maxdiff = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                mindiff++;
                maxdiff++;
            }
            if(s[i] == ')'){
                mindiff = max(mindiff-1,0); // mindiff--;
                maxdiff--;   
            }
            if(s[i] == '*'){
                mindiff = max(mindiff-1,0); // mindiff--;
                maxdiff++;
            }
            if(maxdiff < 0) return false;
        }
        return mindiff == 0;
    }

    // ii) My Initial approach, Using Recursion and DP :

    // beats 100%

    // bool checkValidString(string s) {
    //     int n = s.size();
    //     vector<vector<int>> memo(n,vector<int> (n,-1));
    //     return solve(0,0,s,memo);
    // }

    // bool solve(int i,int balance,string& s,vector<vector<int>>& memo){
    //     int n = s.size();
    //     if(balance < 0){
    //         return false;
    //     }
    //     if(i == n){
    //         if(balance == 0) return true;
    //         else return false;
    //     }
    //     if(memo[i][balance] != -1) return memo[i][balance];
    //     if(s[i] == '('){
    //         return memo[i][balance] = solve(i+1,balance+1,s,memo);
    //     }
    //     if(s[i] == ')'){
    //         return memo[i][balance] = solve(i+1,balance-1,s,memo);
    //     }
    //     if(s[i] == '*'){
    //         //1st option
    //         bool x = solve(i+1,balance + 1,s,memo);
    //         //2nd option
    //         bool y = solve(i+1,balance,s,memo);
    //         //3rd option
    //         bool z = solve(i+1,balance - 1,s,memo);
    //         return memo[i][balance] = (x || y || z);
    //     }
    //     return true;
    // }