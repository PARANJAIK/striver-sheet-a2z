// Q) Count total set Bits -> https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Count+total+set+bits

    // Ans) 
    
    // i) My approach, using combinatorics and recursion : 
    
    int countSetBits(int n)
    {
        // Your logic here
        if(n == 1){
            return 1;
        }
        int index = -1;
        for(int i=30;i>=0;i--){
            if(n&(1<<(i))){
                index = i;
                break;
            }
        }
        if(index == -1) return 0;
        int ans = 0;
        ans = (index/2.0)*(1<<index) + 1;
        int d = n - (1<<index);
        ans += (d + countSetBits(d));
        return ans;
    }
    
    // ii) GFG approach observing the pattern of binary form of numbers : 
    
    // int countSetBits(int n)
    // {
    //     //Ignoring 0 as all the bits are unset. 
    //     n++;
    //     int count=0;
        
    //     //Counting set bits from 1 to n.
    //     for( int x=2 ; x/2<n ; x=x*2 )
    //     {
    //         //Total count of pairs of 0s and 1s.
    //         int quotient = n/x;
    //         //quotient gives the complete count of pairs of 1s.
    //         //Multiplying it with the (current power of 2)/2 will 
    //         //give the count of 1s in the current bit.
    //         count += quotient * x / 2;
            
    //         int remainder = n%x;
    //         //If the count of pairs is odd then we add the remaining 1s 
    //         //which could not be grouped together. 
    //         if(remainder > x/2)
    //             count += remainder - x/2;
    //     }
        
    //     //returning count of set bits.
    //     return count;
    // }