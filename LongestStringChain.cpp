// Q) Longest String Chain -> https://leetcode.com/problems/longest-string-chain/description/

    // Ans) 

    // i) My approach (SIMILAR TO LIS):

    // NOTE : We need to use a comparator function in the inbuilt sort in here,to sort the vector of strings according to the length.

    static bool comp(string& s1,string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[j].size() == words[i].size() - 1){
                    if(predecessor(words[j],words[i]) && dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                    }
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }

    bool predecessor(string& a,string& b){
        int i=0,j=0;
        int len = 0;
        while(i<a.size() && j<b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
                len++;
            }
            else{
                j++;
            }
        }
        if(len == a.size()) return true;
        else return false;
    }
