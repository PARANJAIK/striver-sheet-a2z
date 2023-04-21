// Q) Find the substring with Maximum Cost : https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/

    // i) My approach : 
 
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int mtn = 0; //minTillNow
        int ans = 0;
        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            auto it = chars.find(s[i]);
            if(it == string::npos){
                sum += s[i] - 96;
                ans = max(ans,sum-mtn);
            }
            else{
                int index = it;
                sum += vals[index];
                mtn = min(mtn,sum);
                ans = max(ans,sum-mtn);
            }
        }
        return ans;
    }

    // ii) Kadane's algorithm approach : 

    // int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    //     vector<int> ar(26,1001);
    //     int m=chars.length(),i=0,j=0,n=s.length(),val=0,ans=0;
    //     for(int i=0;i<m;i++){
    //         ar[chars[i]-'a']=vals[i];
    //     }
    //     for(int i=0;i<26;i++){
    //         if(ar[i]==1001){
    //             ar[i]=i+1;
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         val+=ar[s[i]-'a'];
    //         ans=max(ans,val);
    //         if(val<0){
    //             val=0;
    //         }
    //     }
    //   return ans;
    // }
