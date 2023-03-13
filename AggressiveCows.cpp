// Q) Aggressive Cows -> https://practice.geeksforgeeks.org/problems/aggressive-cows/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=aggressive-cows

    // Ans) 

    bool check(int mid,vector<int>& stalls,int n,int k){
        int prev = stalls[0];
        int cnt = 1;
        for(auto curr : stalls){
            if(curr - prev >= mid){
                cnt++;
                prev = curr;
            } 
            if(cnt == k) return true;
        }
        return false;
    }


    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int low = 0,high = 1e9;
        sort(stalls.begin(),stalls.end());
        high = stalls[n-1] - stalls[0];
        while(high-low>1){
            int mid = (low+high)>>1;
            bool x = check(mid,stalls,n,k);
            if(x){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        if(check(high,stalls,n,k)) return high;
        else return low;
    }