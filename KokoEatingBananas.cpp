// Q) Koko Eating Bananas -> https://leetcode.com/problems/koko-eating-bananas/description/

    // Ans) 

    // i) My approach : Its a simple Binary search problem using Predicate Function.

    // NOTE : We need to note that in the check() function if we use (float) in place of (double) we will fail at few test cases due to lesser precision. Hence using double is mandatory.

    bool check(int mid,int h,vector<int>& piles){
        int temp = 0;
        for(int i=0;i<piles.size();i++){
           temp += ceil(piles[i]/(double)mid);
        }
        if(temp<=h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high=0;
        for(int i=0;i<piles.size();i++){
           high = max(high,piles[i]);
        }
        while(high-low>1){
            int mid = (low+high)>>1;
            bool x = check(mid,h,piles);
            if(x){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(check(low,h,piles)) return low;
        else return high;
    }