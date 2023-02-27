// Q) Max Sum in sub-arrays -> https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category=&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays

    // Ans) Approach : In any subarray if two non-adjacent elements are the first and second smallest, then obviously the sum of the second smallest and its adjacent would be clearly having more sum. So definitely the answer going to be in the adjacent pair of elements.
    
        long long pairWithMaxSum(long long arr[], long long n)
    {
        // Your code goes here
        long long int ans = INT_MIN;
        // long long int first = arr[0];
        // long long int second = arr[0];
        // for(int i=1;i<n;i++){
        //     if(first == second){
        //         (arr[i-1]<arr[i]) ? second = arr[i] : first = arr[i];
        //         if(first + second > ans) ans = first + second;
        //     }
        //     else{
        //         if(arr[i]<first) first = second = arr[i];
        //         else if(arr[i]<second){
        //             first = arr[i];
        //             if(first + second > ans) ans = first + second;
        //         }
        //         else{
        //             first = second;
        //             second = arr[i];
        //             if(first + second > ans) ans = first + second;
        //         }
        //     }
        // }
        for(int i=1;i<n;i++){
            if(arr[i]+arr[i-1] > ans) ans = arr[i] + arr[i-1];
        }
        return ans;
    }