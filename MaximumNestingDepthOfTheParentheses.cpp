// Q) Maximum nesting depth of the parentheses -> https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

    // Ans) 

    // i) My approach : 

    int maxDepth(string s) {
        int n = s.size();
        int balance = 0;
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                balance++;
                maxi = max(maxi,balance);
            }
            else if(s[i] == ')'){
                balance--;
                if(balance == 0){
                   ans = max(ans,maxi);
                   maxi = 0;
                }
            }
        }
        return ans;
    }