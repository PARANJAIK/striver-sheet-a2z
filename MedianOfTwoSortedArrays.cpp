//    Q) Median of Two Sorted Arrays -> https://leetcode.com/problems/median-of-two-sorted-arrays/description/

                                    // ->https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=66


    // Ans) i) My approach : Lengthy code but proper logic.

    // int bs(vector<int> a,int l,int h,int target){
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
    
    // int kthElement(vector<int>& a1, vector<int>& a2, int n, int m, int k)
    // {
    //     int l1 = 0, l2 = 0, h1 = n-1, h2 = m-1;
    //     k--;
    //     while(l1<=h1 && l2<=h2){
    //         int m1 = (l1+h1)>>1;
    //         int m2 = (l2+h2)>>1;
    //         int length1,length2,length;
    //         if(a1[m1]<a2[m2]){
    //             int index = bs(a2,l2,m2,a1[m1]);
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
    //             int index = bs(a1,l1,m1,a2[m2]);
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

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     if((m+n)%2==1){
    //         int x = kthElement(nums1,nums2,m,n,(m+n+1)/2);
    //         return (double)x;
    //     }
    //     else{
    //         int x = kthElement(nums1,nums2,m,n,(m+n)/2);
    //         int y = kthElement(nums1,nums2,m,n,(m+n)/2+1);
    //         double ans = (x+y)/(double)2;
    //         return ans;
    //     }
    // }
 
    // ii) Stirver's solution: Small code and also more optimal logic.

    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0,high = n1;
        while(low<=high){
            int cut1 = (low+high)>>1;
            int cut2 = (n1+n2+1)/2 - cut1;
            int left1 = cut1==0?INT_MIN : nums1[cut1-1];
            int left2 = cut2==0?INT_MIN : nums2[cut2-1];
            int right1 = cut1==n1?INT_MAX : nums1[cut1];
            int right2 = cut2==n2?INT_MAX : nums2[cut2];
            if(left1 <= right2 && left2 <= right1){
                if((n1+n2)%2==0) return (max(left1,left2) + min(right1,right2))/2.0;
                else return max(left1,left2);
            }
            else if(left1 > right2){
                high = cut1-1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }