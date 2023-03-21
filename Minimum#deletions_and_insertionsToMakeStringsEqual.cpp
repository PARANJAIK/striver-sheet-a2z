// 	Q) Minimum number of deletions ans insertions to make two strings equal -> https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-number-of-deletions-and-insertions0209

    // Ans) 
    
    // i) My approach :
	
	int minOperations(string word1, string word2) 
	{ 
	    // Your code goes here
	    int l = longestCommonSubsequence(word1,word2);
        int n = word1.size();
        int m = word2.size();
        return (n+m - 2*l);
	} 
	
	int longestCommonSubsequence(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> tab(n+1,vector<int> (m+1));
        for(int i=0;i<n+1;i++){
            tab[i][m] = 0;
        }
        for(int j=0;j<m+1;j++){
            tab[n][j] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i] == t[j]) tab[i][j] = 1 + tab[i+1][j+1];
                else tab[i][j] = max(tab[i+1][j],tab[i][j+1]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<tab[i][j]<<" ";    // TO PRINT THE DP TABULATION ARRAY
        //     }
        //     cout<<endl;
        // }
        return tab[0][0];
    }