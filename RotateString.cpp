// Q) Rotate String -> https://leetcode.com/problems/rotate-string/description/

    // Ans) 

    // i) My approach : 

    // NOTE : THE LEETCODE EDITORIAL HAS SOME BIG DANGEROUS BORING AND CRAZY APPROACHES WHICH ARE OFCOURSE BETTER THAN MINE.

    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == goal[0]){
                string temp = s.substr(i) + s.substr(0,i);
                if(temp == goal) return true;
            }
        }
        return false;
    }