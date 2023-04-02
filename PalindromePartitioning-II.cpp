 // Q) Palindrome Partitioning - II -> https://leetcode.com/problems/palindrome-partitioning-ii/

   // ******** explanation of best solution -> https://leetcode.com/problems/palindrome-partitioning-ii/solutions/42212/two-c-versions-given-one-dp-28ms-one-manancher-like-algorithm-10-ms/?orderBy=most_votes

    // Ans)

    // i) BEST Approach : (Manacher like solution)

     int minCut(string s) {
        const int N = s.size();
        if(N<=1) return 0;
        
        int i, j, minCUTS[N+1];
        for(i=0; i<=N; ++i) minCUTS[i] = i-1;
        
        for(i=1;i<N;i++)
        {
            for(j=0;(i-j)>=0 && (i+j)<N && s[i-j]== s[i+j]; ++j) // odd-length substrings 
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j]);

            for(j=0;(i-j-1)>=0 && (i+j)<N && s[i-j-1]== s[i+j]; ++j) // even-length substrings
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j-1]);
        }
        return minCUTS[N];
    }

    // ii) 2nd BEST solution :

    // int minCut(string s) {
    //         const int N = s.size();
    //         if(N<=1) return 0;
    //         int i,j;
    //         bool isPalin[N][N];
    //         fill_n(&isPalin[0][0], N*N, false);
    //         int minCuts[N+1];
    //         for(i=0; i<=N; ++i) minCuts[i] = i-1;
            
    //         for(j=1; j<N; ++j)
    //         {
    //             for(i=j; i>=0; --i)
    //             {
    //                 if( (s[i] == s[j]) && ( ( j-i < 2 ) || isPalin[i+1][j-1] ) )
    //                 {
    //                     isPalin[i][j] = true;
    //                     minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);    
    //                 }
    //             }
    //         }
    //         return minCuts[N];
            
    //     }

    // iii) MY approach : (PASSED BUT VERY VERY SLOW COMPARED TO BEST SOLUTION)

    // REASON FOR LOW SPEED OF MY APPROACH : Checking if a substring is a palindrome for every particular substring from scratch.

    // int minCut(string s){
    //     int n = s.size();
    //     vector<int> tab(n+1,-1);
    //     for(int i=n-1;i>=0;i--){
    //         int temp = INT_MAX;
    //         string a = "";
    //         string a_rev = "";
    //         for(int j = i;j<n;j++){
    //             // string a = s.substr(i,j-i+1);
    //             a.push_back(s[j]);
    //             a_rev.insert(a_rev.begin(),s[j]);
    //             if(a == a_rev){
    //                 temp = min(temp,1+tab[j+1]);
    //             }
    //         }
    //         tab[i] = temp;
    //     }
    //     return tab[0];
    // }