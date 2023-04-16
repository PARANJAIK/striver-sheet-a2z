 // Q) Minimum Additions to Make Valid String : 

    // i) My approach :

    // int addMinimum(string word) {
    //     int ans = 0;
    //     char cur = word[0];
    //     int i = 1;
    //     int n = word.size();
    //     while(i < n){
    //         if((cur + 1)%3 == word[i]%3){
    //             cur = word[i];
    //             i++;
    //         }
    //         else{
    //             ans++;
    //             cur = cur + 1;
    //         }
    //     }
    //     ans += (int)(word[0] - 97);
    //     if(word[n-1] == 'a') ans += 2;
    //     else if(word[n-1] == 'b') ans++;
    //     return ans;
    // }

    // ii) Better Approach : 

        int addMinimum(string word) {
        int k = 0, prev = 'z';
        for (char& c: word) {
            k += c <= prev;
            prev = c;
        }
        return k * 3 - word.size();
    }
