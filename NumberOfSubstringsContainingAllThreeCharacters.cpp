// Q) NumberOfSubstringsContainingAllThreeCharacters -> https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

    // Ans) 

    // i) LEE sir first approach : 

    // int numberOfSubstrings(string s) {
    //     int count[3] = {0, 0, 0},res = 0 , i = 0, n = s.length();
    //     for (int j = 0; j < n; ++j) {
    //         ++count[s[j] - 'a'];
    //         while (count[0] && count[1] && count[2])
    //             --count[s[i++] - 'a'];
    //         res += i;
    //     }
    //     return res;
    // }

    // ii) My 1st approach : 

    // int numberOfSubstrings(string s){
    //     int n = s.size(),i = 0,j = 0;
    //     int ans = 0;
    //     unordered_map<char,int> m;
    //     while(j < n){
    //         m[s[j]]++;
    //         while(m.size() == 3){
    //             ans += (n-j);
    //             m[s[i]]--;
    //             if(m[s[i]] == 0) m.erase(s[i]);
    //             i++;
    //         }
    //         j++;
    //     }
    //     return ans;
    // }

    // iii) My 1st approach with a little improved implementation:

    // NOTE : THE IMPROVEMENT HERE IS THAT USING AN ARRAY INSTEAD OF MAP

    int numberOfSubstrings(string s){
        int n = s.size(),i = 0,j = 0;
        int ans = 0;
        int count[3] = {0,0,0};
        while(j < n){
            count[s[j] - 97]++;
            while(count[0] && count[1] && count[2]){
                ans += (n-j);
                count[s[i]-97]--;
                i++;
            }
            j++;
        }
        return ans;
    }

    // iv) My 2nd approach : 

    // int numberOfSubstrings(string s) {
    //     return solve(s,3) - solve(s,2);
    // }

    // int solve(string s,int k){
    //     int i = 0;
    //     int j = 0;
    //     int n = s.size();
    //     unordered_map<char,int> m;
    //     int ans = 0;
    //     while(j < n){
    //         m[s[j]]++;
    //         while(m.size() > k){
    //             m[s[i]]--;
    //             if(m[s[i]]==0) m.erase(s[i]);
    //             i++;
    //         }
    //         ans += (j-i+1);
    //         j++;
    //     }
    //     return ans;
    // }
    
    // v) LEE sir 2nd approach : 

    // int numberOfSubstrings(string s) {
    //     int last[3] = {-1, -1, -1}, res = 0, n = s.length();
    //     for (int i = 0; i < n; ++i) {
    //         last[s[i] - 'a'] = i;
    //         res += 1 + min({last[0], last[1], last[2]});
    //     }
    //     return res;
    // }
