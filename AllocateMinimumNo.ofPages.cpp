// Q) Allocate Minimum Number of Pages -> https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=allocate-minimum-number-of-pages

    // Ans)
    
    // i) My approach : Using Greedy logic, picture available on github and commited as my approach pictures.
    
    // ii) Striver's approach : Using Binary Search(We use the minimum possible ans as low and the maximum possible ans as high, and run a binary search to find the minimum ans which is practically possible.)
    
    // bool check(int maxpages,int a[],int n,int m){
    //     int cnt = 0;
    //     int pages = 0;
    //     for(int i=0;i<n;i++){
    //         if(pages + a[i] <= maxpages){
    //             pages += a[i];
    //         }
    //         else{
    //             cnt++;
    //             if(a[i] <= maxpages) pages = a[i];
    //             else return false;
    //         }
    //     }
    //     if(pages <= maxpages) cnt++;
    //     if(cnt <= m) return true;
    //     else return false;
    // }
    
    // int findPages(int a[], int n, int m) 
    // {
    //     //code here
    //     int low = INT_MAX;
    //     int high =0 ;
    //     for(int i=0;i<n;i++){
    //         if(a[i] < low) low = a[i];
    //         high += a[i];
    //     }
    //     if(m > n) return -1;
    //     // int ans = -1;
    //     // while(low<=high){
    //     //     int mid = (low+high)>>1;
    //     //     bool x = check(mid,a,n,m);
    //     //     if(x){
    //     //         ans = mid;
    //     //         high = mid - 1;
    //     //     }
    //     //     else{
    //     //         low = mid + 1;
    //     //     }
    //     // }
    //     // return ans;
    //     while(high-low>1){
    //         int mid = (low+high)>>1;
    //         bool x = check(mid,a,n,m);
    //         if(x){
    //             high = mid;
    //         }
    //         else{
    //             low = mid+1;
    //         }
    //     }
    //     if(check(low,a,n,m)) return low;
    //     else return high;
    // }