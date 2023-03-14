// Q) kth Missing Element -> 

// i) GFG variant : https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-missing-element


// int KthMissingElement(int arr[], int n, int k)
// {
//     // Complete the function
//     // int n = arr.size(); 
//         int low = 0,high = n-1;
//         int extra = arr[0] - 1;
//         if(arr[high] - n - extra < k){
//             return -1;
//         }
//         else{
//             while(high-low>1){
//                 int mid = (low+high)>>1;
//                 int ktillnow = arr[mid] - (mid+1) -extra;
//                 if(ktillnow < k){
//                     low = mid;
//                 }
//                 else{
//                     high = mid;
//                 }
//             }
//             int diff = k - (arr[low]-low-1 - extra);
//             return arr[low] + diff;
//         }
// }

// ii) Leetcode variant : 

//   int findKthPositive(vector<int>& arr, int k) {
//         int n = arr.size(); 
//         int low = 0,high = n-1;
//         if(arr[high] - n < k){
//             int diff = k - arr[high] + n;
//             return arr[high] + diff;
//         }
//         else if(arr[low]-1 >= k){
//             return k;
//         }
//         else{
//             while(high-low>1){
//                 int mid = (low+high)>>1;
//                 int ktillnow = arr[mid] - (mid+1);
//                 if(ktillnow < k){
//                     low = mid;
//                 }
//                 else{
//                     high = mid;
//                 }
//             }
//             int diff = k - (arr[low]-low-1);
//             return arr[low] + diff;
//         }
//     }