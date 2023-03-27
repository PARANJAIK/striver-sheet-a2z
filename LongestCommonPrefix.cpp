// Q) Longest Common Prefix -> https://leetcode.com/problems/longest-common-prefix/description/

    // Ans) 

    // i) My approach : ITS COOL WITH O(n) time and O(1) space;

    // NOTE : LEETCODE EDITORIAL HAS BINARY SEARCH APPROACH, DIVIDE AND CONQUER APPROACH OF THIS PROBLEM, BUT THEY HAVE HIGHER COMPLEXITIES. MY APPROACH IS BETTER OVER THEM. 

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string s = strs[0];
        for(int i=1;i<n;i++){
            string t = strs[i];
            int j=0,k=0;
            while(j < s.size() && k < t.size() && s[j] == t[k]){
                j++;
                k++;
            }
            s = t.substr(0,k);
            if(s == "") break;
        }
        return s;
    }