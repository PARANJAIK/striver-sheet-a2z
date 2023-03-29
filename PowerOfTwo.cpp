// Q) Power of Two -> https://leetcode.com/problems/power-of-two/description/

    bool isPowerOfTwo(int n) {
        for(int i=0;i<31;i++){  // Its not i<32 because the last bit represents sign
            int x = 1<<i;
            if(x == n) return true;
        }
        return false;
    }