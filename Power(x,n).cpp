// Q) Pow(x,n) -> https://leetcode.com/problems/powx-n/

    // Ans) 

    // i) COOL APPROACH : 

    double myPow(double x, int n) {
        if(n==1) return x;
        if(n==0) return 1;
        if(n==-1) return 1/x;
        double y = myPow(x,n/2);
        if(n%2==0) return y*y;
        else{
            if(n>0) return x*y*y;
            else return (1/x)*y*y;
        }
    }
};

// class Solution {
//     public :double myPow(double x, int n) {
//         if(x==0) return 0;
//         if(n==0) return 1;
        
//         if(n>0) return helper(x, n);
//         else{
//             if(n == INT_MIN){
//                 return (1/x)*(1/helper(x,INT_MAX));
//             }
//             else return 1/helper(x,-n);
//         }
//     }
    
//     public: double helper(double x, int n){
//         if(n==0) return 1;
//         double half = helper(x, n/2);
//         if(n%2==1) return half*half*x;
//         return half*half;
//     }