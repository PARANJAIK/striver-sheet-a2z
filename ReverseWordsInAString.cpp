 // Q) Reverse Words in a String -> https://leetcode.com/problems/reverse-words-in-a-string/description/

    // i) My approach :

    // NOTE: O(n) time and O(1) space approach :

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