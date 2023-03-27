 // Q) Roman To Integer -> https://leetcode.com/problems/roman-to-integer/description/

    // Ans) 

    // i) My approach : 

    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        m['I'] = 1;m['V'] = 5;m['X'] = 10;m['L'] = 50;m['C'] = 100;m['D'] = 500;m['M'] = 1000;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i != n-1 && m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }