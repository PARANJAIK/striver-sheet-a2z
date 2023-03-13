// Q) kth Element of two Sorted Arrays -> https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array
 
    // Ans) 
    
    // i) My approach : Lengthy code but proper logic.
    
    
    // int bs(int a[],int l,int h,int target){
    //     if(target<a[l]){
    //         return l-1;
    //     }
    //     else if(target>=a[h]){
    //         return h;
    //     }
    //     else{
    //         while(h-l>1){
    //             int mid=(l+h)>>1;
    //             if(a[mid]<=target){
    //                 l = mid;
    //             }
    //             else{
    //                 h = mid-1;
    //             }
    //         }
    //         if(a[h]<=target) return h;
    //         else return l;
    //     }
        
    // }
    
    // int kthElement(int a1[], int a2[], int n, int m, int k)
    // {
    //     int l1 = 0, l2 = 0, h1 = n-1, h2 = m-1;
    //     k--;
    //     while(l1<=h1 && l2<=h2){
    //         int m1 = (l1+h1)>>1;
    //         int m2 = (l2+h2)>>1;
    //         int length1,length2,length;
    //         if(a1[m1]<a2[m2]){
    //             int index = bs(a2,l2,h2,a1[m1]);
    //             length1 = m1-l1+1;
    //             length2 = index-l2+1;
    //             length = length1+length2;
    //             if(length==k+1){
    //                 return a1[m1];
    //             }
    //             else if(length>k+1){
    //                 h1 = m1-1;
    //                 h2 = index;
    //             }
    //             else{
    //                 k=k-length;
    //                 l1 = m1+1;
    //                 l2 = index+1;
    //             }
    //         }
    //         else{
    //             int index = bs(a1,l1,h1,a2[m2]);
    //             length1 = index - l1 + 1;
    //             length2 = m2 - l2 + 1;
    //             length = length1 + length2;
    //             if(length==k+1){
    //                 return a2[m2];
    //             }
    //             else if(length>k+1){
    //                 h1 = index;
    //                 h2 = m2-1;
    //             }
    //             else{
    //                 k = k-length;
    //                 l1 = index+1;
    //                 l2 = m2+1;
    //             }
    //         }
    //     }
    //     if(h2<l2){
    //         return a1[l1+k];
    //     }
    //     else{
    //         return a2[l2+k];
    //     }
    // }
    
    // ii) Striver's approach : Small code and more optimal logic.
    
    int kthElement(int arr1[],int arr2[],int n,int m,int k){
        if(n>m){
            return kthElement(arr2,arr1,m,n,k);
        }
        int low = max(0,k-m), high = min(k,n);
        while(low<=high){
            int cut1 = (low+high)>>1;
            int cut2 = k- cut1;
            int l1= cut1==0? INT_MIN : arr1[cut1-1];
            int l2= cut2==0? INT_MIN : arr2[cut2-1];
            int r1= cut1==n? INT_MAX : arr1[cut1];
            int r2= cut2==m? INT_MAX : arr2[cut2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                high=cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 1;
    }