// Q) Square root of a number in O(logN) -> https://practice.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

    // Ans) Apply Binary search :
  
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int low = 1,high = x;
        while(high-low > 1){
            long long int mid = (low+high)>>1;
            if(mid*mid == x){
                return mid;
            }
            if(mid*mid > x){
                high = mid-1;
            }
            else{
                low = mid;
            }
        }
        if(high*high <= x) return high;
        else return low;
    }