// 	Q) Max Sum without Adjacents -> https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents

    // Ans) 
    
    // i) My initial recursion approach, but couldn't memoize it.
	
// 	int findMaxSum(int *arr, int n) {
// 	    // code here
// 	    int sum = 0;
// 	    bool flag = true;
// 	    return solve(0,arr,n,sum,flag);
// 	}
	
// 	int solve(int index,int *arr,int n,int sum,bool flag){
// 	    if(index == n){
// 	        return sum;
// 	    }
// 	    int noconsider = solve(index+1,arr,n,sum,true);
// 	    int yesconsider = INT_MIN;
// 	    if(flag){
// 	        yesconsider = solve(index+1,arr,n,sum+arr[index],false);
// 	    }
// 	    return max(noconsider,yesconsider);
// 	}

    // ii) Proper recursive approach followed by memoization (TOP-DOWN approach) :

    // vector<int> memo;

    // int findMaxSum(int *arr,int n){
    //     memo.assign(n,-1);
    //     return solve(0,arr,n);
    // }
    
    // int solve(int index,int *arr,int n){
    //     if(index >= n){
    //         return 0;
    //     }
    //     if(memo[index] == -1){
    //     int nopick = solve(index+1,arr,n);
    //     int pick = arr[index] + solve(index+2,arr,n);
    //     memo[index] = max(pick,nopick);    
    //     }
    //     return memo[index];
    // }
    
    // iii) BOTTOM-UP approach : 
    
    // int findMaxSum(int *arr,int n){
    //     vector<int> tab(n+2);
    //     tab[n+1] = 0;
    //     tab[n] = 0;
    //     for(int i=n-1;i>=0;i--){
    //         tab[i] = max(tab[i+1] , arr[i] + tab[i+2]);
    //     }
    //     return tab[0];
    // }
    
    // iv) Space Optimized BOTTOM-UP approach : 
    
    int findMaxSum(int *arr,int n){
        int cur,next,next2;
        next = next2 = 0;
        for(int i=n-1;i>=0;i--){
            cur = max(next, arr[i] + next2);
            next2 = next;
            next = cur;
        }
        return cur;
    }