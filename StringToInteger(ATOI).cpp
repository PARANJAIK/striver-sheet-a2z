//  Q) String to Integer -> https://leetcode.com/problems/string-to-integer-atoi/description/

  // Ans) 

  // i) My approach : COOL BUT NOT OPTIMAL, I UNNECESSARILY USED THE vector<long long> ,instead we can do it inside the for loop

    // int myAtoi(string s) {
    //     int flag = 1;
    //     vector<long long int> v;
    //     int n = s.size();
    //     int whitespace=1,sign=1;
    //     for(int i=0;i<n;i++){
    //         if(s[i]==' ' && whitespace){
    //             continue;
    //         }
    //         else if((s[i]=='-' || s[i]=='+') && sign){
    //             whitespace = 0;
    //             if(s[i]=='-') flag=0;
    //             sign = 0;
    //         }
    //         else if(48<=s[i] && s[i]<=57){
    //             whitespace = 0;
    //             sign = 0;
    //             v.push_back(s[i]-48);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     int m = v.size();
    //     long long int ans = 0;
    //     for(int i=0;i<m;i++){
    //         int x = m-1-i;
    //         while(x--){
    //             if(1LL*v[i]*10 <=INT_MAX){
    //                 v[i]*=10;
    //             }
    //             else{
    //                 if(!flag) return INT_MIN;
    //                 else return INT_MAX;
    //             }
    //         }
    //         ans+=v[i];
    //     }
    //     if(!flag){
    //         if(ans>=INT_MAX+1LL){
    //             return INT_MIN;
    //         }
    //         else{
    //             ans -= 2*ans;
    //             return ans;
    //         }
    //     }
    //     else{
    //         if(ans>INT_MAX) return INT_MAX;
    //         else return ans;
    //     }
    // }

    // ii) Optimal approach : 

  int myAtoi(string s) {
        string real_num;
        int sign = 1;
        int n = s.length();
        int i = 0;
        int sum = 0;
        //skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int cur_digit = s[i] - '0';
            //overflow and underflow
            if (sum > INT_MAX / 10 || sum == INT_MAX / 10 && cur_digit > INT_MAX % 10) {
                return sign ==  1 ? INT_MAX : INT_MIN;
            }
            sum = sum * 10 + cur_digit;
            i++;
        }

        return sum * sign;
    }