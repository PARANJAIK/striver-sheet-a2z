// 	Q) Nth root of M using Binary Search -> https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

    // Ans) 
    
    // i) If we have to return a perfect integer root else -1.
	
// 	long long int compute(int n,int num,int m){
// 	    long long int ans = 1;
// 	    while(n--){
// 	        ans *= num;
// 	        if(ans > m*1LL) break;
// 	    }
// 	    return ans;
// 	}
	
// 	int NthRoot(int n, int m)
// 	{
// 	    // Code here.
// 	    int low = 1,high = m;
// 	    while(low <= high){
// 	        int mid = (low+high)>>1;
// 	        long long int temp = compute(n,mid,m);
// 	        if(temp == m){
// 	            return mid;
// 	        }
// 	        else if(temp > m){
// 	            high = mid - 1;
// 	        }
// 	        else{
// 	            low = mid + 1;
// 	        }
// 	    }
// 	    return -1;
// 	}  
	
// 	ii) If we have to return the nth root upto 6 decimal places :
	
	double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}