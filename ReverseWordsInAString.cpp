 // Q) Reverse Words in a String -> https://leetcode.com/problems/reverse-words-in-a-string/description/

    // i) My approach :

    // NOTE: O(n) time and O(1) space approach : (IN-PLACE APPROACH)

    // string reverseWords(string s) {
    //     reverse(s.begin(),s.end());
    //     int i=0;
    //     int x = 0;
    //     int n = s.size();
    //     while(i < n - x){
    //         int j = i;
    //         while(j < n-x && s[j] != ' '){
    //             j++;
    //         }
    //         reverse(s.begin() + i,s.begin() + j);
    //         i = j;
    //         while(j < n-x && s[j] == ' '){
    //             j++;
    //         }
    //         if(j-i > 1){
    //             s.erase(i+1,j-i-1);
    //             x += j-i-1;
    //         }
    //         i = i + 1;
    //     }
    //     if(s[0] == ' ') s.erase(0,1);           // Cause the above loop will leave 1 initial space un deleted.
    //     if(s[s.size()-1] == ' ') s.pop_back();  // cause the above loop will leave 1 end space un deleted.
    //     return s;
    // }

    // ii) Other approach : 

    // NOTE : O(n) time and O(n) space approach (but takes slightly less time, so thats cool).

    // About Stringstream : https://www.geeksforgeeks.org/stringstream-c-applications/

    // string reverseWords(string s) {
    //     vector<string> words;
    //     stringstream ss(s);
    //     string tmp;
    //     while (ss >> tmp)
    //         words.push_back(tmp);

    //     string ans;
    //     for (int i = words.size() - 1; i >= 0; --i) {
    //         if (i != words.size() - 1) ans += " ";
    //         ans += words[i];
    //     }
    //     return ans;
    // }

    // iii) GFG variant -> https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-words-in-a-given-string

    // Ans) 

    // string reverseWords(string s) 
    // { 
    //     // code here 
    //     vector<string> v;
    //     string t;
    //     int n = s.size();
    //     for(int i=0;i<n;i++){
    //         if(s[i] == '.' && !t.empty()){
    //             v.push_back(t);
    //             t.clear();
    //         }
    //         else if(s[i] != '.'){
    //             t.push_back(s[i]);
    //         }
    //     }
    //     if(!t.empty()){
    //         v.push_back(t);
    //         t.clear();
    //     }
    //     int x = v.size();
    //     for(int i=x-1;i>=0;i--){
    //         for(auto ch : v[i]){
    //             t.push_back(ch);
    //         }
    //         t = t + '.';
    //     }
    //     t.pop_back();
    //     return t;
    // } 
