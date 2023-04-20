 // Q) Mice and Cheese -> https://leetcode.com/problems/mice-and-cheese/description/

    // Ans) 

    // i)

       //WITHOUT USING EXTRA VECTOR SPACE 

    //     int miceAndCheese(vector<int> A, vector<int>& B, int k) {
    //     int n = A.size(), res = 0;
    //     for (int i = 0; i < n; ++i) {
    //         A[i] -= B[i];
    //         res += B[i];
    //     }
    //     sort(A.rbegin(),A.rend());
    //     for(int i=0;i<k;i++){
    //         res += A[i];
    //     }
    //     return res;
    // }

    // ii)

    int miceAndCheese(vector<int>&r1, vector<int>& r2, int k) {
       priority_queue<int>pq;
        long long int ans=0;
        for(int i=0;i<r1.size();i++){
           pq.push(r1[i]-r2[i]);
            ans+=r2[i];
        }
        while(k!=0){
          ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }

    // iii) My initial approach:

    // USING EXTRA VECTOR SPACE

    
    // static bool cmp1(pair<int,int>& a,pair<int,int>& b){
    //     return (a.first - a.second > b.first - b.second);
    // }
    
    // int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    //     int n = reward1.size();
    //     vector<pair<int,int>> v;
    //     for(int i=0;i<n;i++){
    //         v.push_back({reward1[i],reward2[i]});
    //     }
    //      sort(v.begin(),v.end(),cmp1);
    //         int ans = 0;
    //         for(int i=0;i<k;i++){
    //             ans += v[i].first;
    //        }
    //         for(int i=k;i<n;i++){
    //             ans += v[i].second;
    //         }
    //         return ans;
    // }
