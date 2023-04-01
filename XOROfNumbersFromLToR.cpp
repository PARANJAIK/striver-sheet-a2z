// Q) Find XOR of numbers from L to R : 
    
    // Ans) 
    
    // i) My approach : 
  
    int findXOR(int l, int r) {
        // complete the function here
        int t = 0;
        if(l%2==1){
            t = l-1;
            l--;
        }
        int d = r - l;
        int ans;
        if(d == 0) ans = l;
        else if((d-1)%4 == 0) ans = 1;
        else if((d-2)%4 == 0) ans = r+1;
        else if((d-3)%4 == 0) ans = 0;
        else if((d-4)%4 == 0) ans = r;
        return ans^t;
    }