 //   Q) Make K-subarray sums equal : https://leetcode.com/problems/make-k-subarray-sums-equal/description/

//    i) Proper approach : 

    //   NOTE : 
        //  1) FIRST POINT IS IF WE ARE GIVEN AN ARRAY OF INTEGERS AND WE NEED TO MAKE ALL THE ARRAY ELEMENTS EQUAL,THEN WE NEED TO MAKE THEM EQUAL TO THE MEDIAN VALUE TO HAVE MINIMUM OPERATIONS.
        // 2) WHEN THE CYCLE ARRAY IS EVEN SIZED, THEN BOTH THE N/2 ELEMENT AND 
        // N/2 - 1 ELEMENT IN THE SORTED CYCLE ARRAY GIVE THE SAME MINIMUM OPERATIONS.

      long long makeSubKSumEqual(vector<int>& arr, int k) {
    long long sz = arr.size(), res = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> cycle;
        for (int j = i; arr[j] != 0; j = (j + k) % sz) {
            cycle.push_back(arr[j]);
            arr[j] = 0;
        }
        nth_element(begin(cycle), begin(cycle) + cycle.size() / 2, end(cycle));
        for (int n : cycle)
            res += abs(n - cycle[cycle.size() / 2]);
    }
    return res;
}

    // ii) My initial approach : (FAILED)

    // long long makeSubKSumEqual(vector<int>& arr, int k) {
    //     long long int ans = 0;
    //     int n = arr.size();
    //     if(n%2 == 0){
    //         if(k == n){
    //             return 0;
    //         }
    //         if(k == n/2){
    //             for(int i=0;i<n/2;i++){
    //                 ans += abs(arr[i] - arr[n/2 + i]);
    //             }
    //             return ans;
    //         }
    //         if(k%2 == 1){
    //             unordered_map<int,int> m;
    //             int maxfreqval;
    //             int maxfreq = 0;
    //             for(int i=0;i<n;i++){
    //                 m[arr[i]]++;
    //                 if(m[arr[i]] > maxfreq){
    //                     maxfreq = m[arr[i]];
    //                     maxfreqval = arr[i];
    //                 }
    //             }
    //             for(int i=0;i<n;i++){
    //                 ans += abs(maxfreqval - arr[i]);
    //             }
    //             return ans;
    //         }
    //         if(k%2 == 0){
    //             unordered_map<int,int> m1,m2;
    //             int maxfreqval = 0;
    //             int maxfreq = 0;
    //             for(int i=0;i<n;i+=2){
    //                 m1[arr[i]]++;
    //                 if(m1[arr[i]] > maxfreq){
    //                     maxfreq = m1[arr[i]];
    //                     maxfreqval = arr[i];
    //                 }
    //             }
    //             for(int i=0;i<n;i+=2){
    //                 ans += abs(maxfreqval - arr[i]);
    //             }
    //             maxfreqval = 0;
    //             maxfreq = 0;
    //             for(int i=1;i<n;i+=2){
    //                 m2[arr[i]]++;
    //                 if(m2[arr[i]] > maxfreq){
    //                     maxfreq = m2[arr[i]];
    //                     maxfreqval = arr[i];
    //                 }
    //             }
    //             for(int i=1;i<n;i+=2){
    //                 ans += abs(maxfreqval - arr[i]);
    //             }
    //             return ans;
    //         }
    //     }
    //     else{
    //         if(k == n){
    //             return 0;
    //         }
    //         else{
    //             unordered_map<int,int> m;
    //             int maxfreqval;
    //             int maxfreq = 0;
    //             for(int i=0;i<n;i++){
    //                 m[arr[i]]++;
    //                 if(m[arr[i]] > maxfreq){
    //                     maxfreq = m[arr[i]];
    //                     maxfreqval = arr[i];
    //                 }
    //             }
    //             for(int i=0;i<n;i++){
    //                 ans += abs(maxfreqval - arr[i]);
    //             }
    //             return ans;
    //         }
    //     }
    //     return 0;
    // }
