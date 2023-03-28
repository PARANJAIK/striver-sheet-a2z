// Q) Count number of substrings with exactly k distinct characters -> https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings

    // Ans) 
    
    // i) FIRST IMPLEMENTATION : (THIS GIVES TLE BECAUSE OF frequent m.size(),m.erase() functions, so simply we can use a freq array like in second implementation.)
    
    
    // long long int substrCount(string s,int k){
    //     return atmostk(s,k) - atmostk(s,k-1);
    // }
    
    // long long int atmostk(string& s,int k){
    //     int n = s.size();
    //     if(n == 0) return 0;
    //     unordered_map<char,int> m;
    //     long long int ans = 0;
    //     int left = 0;
    //     for(int i=0;i<n;i++){
    //         m[s[i]]++;
    //         while(m.size() > k){
    //             m[s[left]]--;
    //             if(m[s[left]] == 0){
    //                 m.erase(s[left]);
    //             }
    //             left++;
    //         }
    //         ans += (i - left + 1);
    //     }
    //     return ans;
    // }
    
    
    // ii) Second Implementation : (Used freq array instead of map).
    
    
      long long int solve(string s, int k)
    {
        int n = s.size();
        int freq[26] = {0};
        int dist_cnt = 0;
        long long int ans = 0;  //ans count
        
        int i=0;  //start of window
        int j=0;  //end of window
        while(j<n)
        {
            freq[s[j]-'a']++;
            if(freq[s[j]-'a'] == 1)
                dist_cnt++;
            
            //if this happen's then we need to shift our window size i.e, known as sliding
            while(dist_cnt > k)
            {
                freq[s[i]-'a']--;
                if(freq[s[i]-'a'] == 0)
                    dist_cnt--;
                i++;
            }
            j++;
            ans += (j-i+1);
        }
        return ans;
    }
    
    
    long long int substrCount(string s, int k) 
    {
        long long int ans = solve(s,k) - solve(s,k-1);
        return ans;
    }