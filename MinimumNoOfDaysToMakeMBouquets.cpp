// Q) Minimum Number of Days to make m bouquets -> https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

//    Ans) 

//    i) My approach : Do a simple Binary search on the number of days using predicate function.

    bool check(vector<int>& bloomday,int mid,int k,int m){
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<bloomday.size();i++){
            if(bloomday[i] <= mid) cnt++;
            else{
                if(cnt!=0){
                    ans += cnt/k;
                }
                cnt = 0;
            }
        }
        if(cnt!=0){
            ans += cnt/k;
        }
        if(ans >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomday, int m, int k) {
        long long int n = bloomday.size();
        if(1LL*m*k > n){
            return -1;
        }
        int low = 1,high=0;
//         for(int i=0;i<n;i++){
//             high = max(high,bloomday[i]);
//         }
        high = *max_element(bloomday.begin(),bloomday.end());
        while(high-low>1){
            int mid = (low+high)>>1;
            bool x = check(bloomday,mid,k,m);
            if(x){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(check(bloomday,low,k,m)) return low;
        else return high;
    }
