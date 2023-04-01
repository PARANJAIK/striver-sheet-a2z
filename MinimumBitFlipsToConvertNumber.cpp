// Q) Minimum Bit Flips to Convert Number -> https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

    // i) My approach : 

    // int minBitFlips(int start, int goal) {
    //     int ans = 0;
    //     for(int i=30;i>=0;i--){
    //        int x = (start&(1<<i)) ? 1 : 0;
    //        int y = (goal&(1<<i)) ? 1 : 0;
    //        if(x != y) ans++;
    //     }
    //     return ans;
    // }

    // ii) My approach : 

    // int minBitFlips(int start,int goal){
    //     int ans = start^goal;
    //     return __builtin_popcount(ans);
    // }

    // iii) Others approach : (I FEEL LIKE THIS IS BETTER)

    int minBitFlips(int start, int goal) {
        int count = 0;
        while(start>0 || goal>0){
            int temp1 = start%2;
            int temp2 = goal%2;
            if(temp1 != temp2){
                count++;
            }
            start /=2; goal /=2;
        }

        return count;
    }