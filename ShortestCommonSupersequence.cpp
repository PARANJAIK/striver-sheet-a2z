 // Q) Shortest Common Supersequence -> https://leetcode.com/problems/shortest-common-supersequence/description/

    // Ans) 

    // i) Striver's approach : (JUST A SMALL MODIFICATION TO MINE, INSTEAD OF FINDING THE LCS AND THEN COMPARING WITH THE GIVEN STRINGS TO FORM THE SHORTEST COMMON SUPERSEQUENCE, WE FORM IT WHILE WE ARE FORMING THE LCS USING THE DP TABLE).

    string shortestCommonSupersequence(string s,string t){
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
        int i=0,j=0;
        string ans;
        while(i<n && j<m){
           if(s[i] == t[j]){
              ans.push_back(s[i]);
              i++;
              j++;
           }
        else{
            if(tab[i+1][j] > tab[i][j+1]){
                ans.push_back(s[i]);
                i++;
            }
            else{
                ans.push_back(t[j]);
                j++;
            }
        }
    }
    while(i<n){
        ans.push_back(s[i]);
        i++;
    }
    while(j<m){
        ans.push_back(t[j]);
        j++;
    }
    return ans;
    }

    // ii) My approach : (THE ONLY DIFFERENCE IS I FIRST FINDED THE LCS AND THEN COMPARED IT WITH GIVEN STRINGS, SO DID FEW UNNECESSARY STEPS, OR CAN SAY LIKE REPEATED A PROCESS TWICE).

//     string shortestCommonSupersequence(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> tab(n+1,vector<int> (m+1));
//         for(int i=0;i<n+1;i++){
//             tab[i][m] = 0;
//         }
//         for(int j=0;j<m+1;j++){
//             tab[n][j] = 0;
//         }
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
//                 if(s[i] == t[j]) tab[i][j] = 1 + tab[i+1][j+1];
//                 else tab[i][j] = max(tab[i+1][j],tab[i][j+1]);
//             }
//         }
//         string lcs = returnlcs(tab,s,t);
//         int l = lcs.size();
//         string ans;
//         int j=0,k=0;
//         for(int i=0;i<l;i++){
//             while(s[j] != lcs[i]){
//                 ans.push_back(s[j]);
//                 j++;
//             }
//             j++;
//             while(t[k] != lcs[i]){
//                 ans.push_back(t[k]);
//                 k++;
//             }
//             k++;
//             ans.push_back(lcs[i]);
//         }
//         while(j < n){
//             ans.push_back(s[j]);
//             j++;
//         }
//         while(k < m){
//             ans.push_back(t[k]);
//             k++;
//         }
//         return ans;
//     }

//     string returnlcs(vector<vector<int>>& tab,string& a,string& b){
//     int n = tab.size() -1;
//     int m = tab[0].size() -1;
//     int i=0,j=0;
//     string ans;
//     while(i<n && j<m){
//         if(a[i] == b[j]){
//             ans.push_back(a[i]);
//             i++;
//             j++;
//         }
//         else{
//             if(tab[i+1][j] > tab[i][j+1]){
//                 i++;
//             }
//             else{
//                 j++;
//             }
//         }
//     }
//     return ans;
// }