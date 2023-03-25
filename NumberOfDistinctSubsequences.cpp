// Q) Number of Distinct Subsequences -> https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-subsequences0909

    // Ans)   
    
    // i) My approach :
  
    int M = 1e9+7;
    
    int distinctSubsequences(string s){
        int n = s.size();
        unordered_map<char,long long int> mapp;
        long long int ans = solve(0,s,mapp);
        return (ans)%M;
    }
    
    long long int solve(int i,string& s,unordered_map<char,long long int>& mapp){
        int n = s.size();
        if(i == n){
            return 1;
        }
        long long int nextans = solve(i+1,s,mapp);
        // getting ans
        long long int ans = nextans*2 - mapp[s[i]];
        // updating the mapp
        mapp[s[i]] = nextans;
        return ans;
    }