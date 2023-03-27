// Q) Isomorphic Strings -> https://leetcode.com/problems/isomorphic-strings/description/

    // Ans) 

    // i) My approach : 

    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> ms,mt;
        for(int i=0;i<n;i++){
            if(ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end()){
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            else if(ms.find(s[i]) != ms.end()){
                if(ms[s[i]] != t[i]) return false;
            }
            else{
                if(mt[t[i]] != s[i]) return false;
            }
        }
        return true;
    }