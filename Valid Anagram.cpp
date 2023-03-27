// Q) Valid Anagram -> https://leetcode.com/problems/valid-anagram/description/

    // Ans) 

    // i) My approach :

    // bool isAnagram(string s, string t) {
    //     unordered_map<char,int> ms,mt;
    //     if(s.size() != t.size()) return false;
    //     int n = s.size();
    //     for(int i=0;i<n;i++){
    //         ms[s[i]]++;
    //         mt[t[i]]++;
    //     }
    //     if(ms.size() != mt.size()) return false;
    //     for(auto it : ms){
    //         if(it.second != mt[it.first]) return false;
    //     }
    //     return true;
    // }

    // ii) My approach same as (i) but with a slight improvement in the implementation : 

    // bool isAnagram(string s, string t) {
    //     if (s.length() != t.length()) return false;
    //     int n = s.length();
    //     unordered_map<char, int> counts;
    //     for (int i = 0; i < n; i++) {
    //         counts[s[i]]++;
    //         counts[t[i]]--;
    //     }
    //     for (auto count : counts)
    //         if (count.second) return false;
    //     return true;
    // }

    // iii) Same approach but use of vector in place of unordered map to speed up:

    // NOTE : THIS APPROACH IS USEFUL TO SPEED UP THE CODE IN CASE OF ONLY LOWERCASE ENGLISH ALPHABETS.

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }