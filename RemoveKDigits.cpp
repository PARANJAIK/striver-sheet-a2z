 // Q) Remove K digits -> https://leetcode.com/problems/remove-k-digits/description/

    // Ans) 

    // i) My approach : 

    string removeKdigits(string num, int k) {
        string ans = "";
        int i = 0;
        int n = num.size();
        while(i < n && k > 0){
            while(ans.size() && k>0 && ans.back() > num[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
            i++;
        }
        while(k > 0){
        ans.pop_back();
        k--;    
        } 
        while(i < n){
            ans.push_back(num[i]);
            i++;
        }
        i = 0;
        while(ans[i] == '0') i++;
        ans = ans.substr(i);
        if(ans.size() == 0) ans += "0";
        return ans;
    }
