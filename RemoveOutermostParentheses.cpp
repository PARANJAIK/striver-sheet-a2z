// Q) remove OuterMost Parentheses -> https://leetcode.com/problems/remove-outermost-parentheses/description/

    // Ans) 

    // i) O(n) time and O(2n) space approach : (NOT BEST)

    // string removeOuterParentheses(string s) {
    //     int n = s.size();
    //     int i=0;
    //     int val = 0;
    //     vector<string> v;
    //     while(i < n){
    //         int j = i;
    //         string t;
    //         val = 1;
    //         t.push_back(s[j]);
    //         while(val!=0){
    //            j++;
    //            if(s[j] == '(') val++;
    //            else val--;
    //            t.push_back(s[j]);
    //         }
    //         v.push_back(t);
    //         i = j+1;
    //     }
    //     string ans = "";
    //     for(auto t : v){
    //         ans = ans + t.substr(1,t.size()-2);
    //     }
    //     return ans;
    // }

    // ii) O(n) time and O(n) space : (NOT BEST)

    // string removeOuterParentheses(string s){
    //     int n = s.size();
    //     int i = 0;
    //     int val = 1;
    //     string ans="";
    //     while(i < n){
    //         int j = i;
    //         val = 1;
    //         while(val != 0){
    //             j++;
    //             if(s[j] == '(') val++;
    //             else val--;
    //         }
    //         ans = ans + s.substr(i+1,j-i-1);
    //         i = j+1;
    //     }
    //     return ans;
    // }

    // iii) O(n) time and O(1) space : (BEST)

    string removeOuterParentheses(string s){
        int n = s.size();
        int i = 0;
        int val = 1;
        int x = 0;
        while(i < n - 2*x){
            int j = i;
            val = 1;
            while(val != 0){
                j++;
                if(s[j] == '(') val++;
                else val--;
            }
            x++;
            s.erase(i,1);
            j = j-1;
            s.erase(j,1);
            i = j;
        }
        return s;
    }