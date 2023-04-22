 // Q) Prime Substraction Operation : https://leetcode.com/problems/prime-subtraction-operation/description/

    // i) My approach : 

    // bool primeSubOperation(vector<int>& nums) {
    //     int n = nums.size();
    //     set<int> s;
    //     for(int i=2;i<=1000;i++){
    //        s.insert(i);
    //     }
    //     for(auto x : s){
    //         int y = x*2;
    //         while(y <= 1000){
    //             s.erase(y);
    //             y += x;
    //         }
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         if(nums[i] < nums[i+1]) continue;
    //         else{
    //             int t = nums[i] - nums[i+1];
    //             auto p = s.upper_bound(t);
    //             if(p == s.end()) return false;
    //             if(*p < nums[i]){
    //                 nums[i] = nums[i] - *p;
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    // ii) Better implementation of same logic : 

    bool sieve[1001];

    bool primeSubOperation(vector<int>& nums) {
        for(int i=0; i<1001; i++) sieve[i] = true;
        int hp = 1000;
        for(int i=2; i*i<=hp; (i==2)?i++:i+=2){
            if(sieve[i]){
                for(int j=i*i; j<=hp; j+=i){
                    sieve[j] = false;
                }
            }
        }
        sieve[1] = false;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]>=nums[i+1]){
                int diff = nums[i]-nums[i+1];
                bool found = false;
                for(int p=diff+1; p<nums[i]; p++){
                    if(sieve[p]){
                        nums[i]-=p;
                        found = true;
                        break;
                    }
                }
                if(!found) return false;
            }
        }
        return true;
    }
