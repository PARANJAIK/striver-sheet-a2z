//    Q) Longest Substring Without Repeating Characters -> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

    // Ans) 

    // i) My approach : 

    // int lengthOfLongestSubstring(string s){
    //     int n = s.size();
    //     int ans = 0;
    //     int i = 0,j=0;
    //     unordered_map<char,int> m;
    //     while(i < n && j < n){
    //         if(m[s[j]] == 0){
    //             m[s[j]]++;j++;
    //         }
    //         else{
    //             ans = max(ans,j-i);
    //             m[s[i]]--;
    //             i++;
    //         }
    //     }
    //     ans = max(ans,j-i);
    //     return ans;
    // }

    // ii) Best approach : 

    int lengthOfLongestSubstring(string s){
        vector<int> mpp(256,-1);    // can also use map<char,int> where we store the index where that character is present at last.
        int left = 0,right = 0;
        int n = s.size();
        int len = 0;
        while(right < n){
            if(mpp[s[right]] != -1) left = max(mpp[s[right]] + 1,left);
            mpp[s[right]] = right;
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
