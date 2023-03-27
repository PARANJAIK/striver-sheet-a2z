// Q) Largest Odd Number in String -> https://leetcode.com/problems/largest-odd-number-in-string/description/

    // i) My initial approach : 

    string largestOddNumber(string num) {
        int n = num.size();
        int j = -1;
        for(int i=n-1;i>=0;i--){
            int number = (int)num[i];
            if(number%2 == 1){
                j = i;
                break;
            }
        }
        string ans = num.substr(0,j+1);
        return ans;
    }