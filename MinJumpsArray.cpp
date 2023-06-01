// Q) Min Jumps Array -> https://www.interviewbit.com/problems/min-jumps-array/

// Ans) 

// i) Other's COOL approach : 

int Solution::jump(vector<int> &A) {
    int n =  A.size();
    if(n == 1){
        return 0;
    }
    if(A[0] == 0){
        return -1;
    }
    vector<int> dp(n,-1);
    dp[0] = 0;
    int current = 0;
    for(int i = 0 ; i < n ; i++){
        if(dp[i] == -1){
            return -1;
        }
        for(int j = current+1 ; j <= min(n-1, A[i]+i); j++){
            dp[j] = dp[i]+1;
            current = min(n-1 , A[i]+i);
        }
    }
    return dp[n-1];
}

// ii) My segment tree approach : 

void segtree(int ind,int low,int high,vector<int>& a,vector<int>& seg){
    if(low == high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)>>1;
    segtree(2*ind + 1,low,mid,a,seg);
    segtree(2*ind + 2,mid+1,high,a,seg);
    seg[ind] = min(seg[2*ind + 1],seg[2*ind + 2]);
    return;
}

int query(int ind,int low,int high,int l,int r,vector<int>& seg){
    if(l <= low && high <= r){
        return seg[ind];
    }
    if(l > high || r < low){
        return INT_MAX;
    }
    int mid = (low+high)>>1;
    int left = query(2*ind + 1,low,mid,l,r,seg);
    int right = query(2*ind + 2,mid+1,high,l,r,seg);
    return min(left,right);
}

void update(int ind,int low,int high,int target,int val,vector<int>& seg){
    if(low == high){
        seg[ind] = val;
        return; 
    }
    int mid = (low+high)>>1;
    if(target <= mid) update(2*ind + 1,low,mid,target,val,seg);
    else update(2*ind +2,mid+1,high,target,val,seg);
    seg[ind] = min(seg[2*ind + 1],seg[2*ind + 2]);
    return;
}

int Solution::jump(vector<int>& a){
    int n = a.size();
    vector<int> dp(n,INT_MAX);
    vector<int> seg(4*n+1,-1);
    dp[n-1] = 0;
    segtree(0,0,n-1,dp,seg);
    for(int i=n-2;i>=0;i--){
        if(a[i] == 0) continue;
        if(i + a[i] >= n-1){
            dp[i] = 1;
            update(0,0,n-1,i,1,seg);
            continue;
        }
        int minn = query(0,0,n-1,i+1,i+a[i],seg);
        if(minn != INT_MAX){
            dp[i] = 1 + minn;
            update(0,0,n-1,i,1+minn,seg);
        }
    }
    return (dp[0] == INT_MAX) ? -1 : dp[0];
}

// ii) My initial failed apporaches without using segment tree:

// int Solution::jump(vector<int> &a){
//     int n = a.size();
//     vector<int> dp(n,INT_MAX-2);
//     // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//     set<pair<int,int>> s;
//     dp[n-1] = 0;
//     // q.push({0,n-1});
//     s.insert({0,n-1});
//     for(int i=n-2;i>=0;i--){
//         if(i + a[i] >= n-1){
//             dp[i] = 1;
//             continue;
//         }
//         // for(int j=1;j<=a[i];j++){
//         //     dp[i] = min(dp[i],1+dp[i+j]);
//         // }
//         // vector<pair<int,int>> temp;
//         // while(true){
//         //     pair<int,int> p = q.top();
//         //     if(p.second <= i + a[i]){
//         //         dp[i] = 1 + p.first;
//         //         break;
//         //     }
//         //     else{
//         //         temp.push_back(p);
//         //         q.pop();
//         //     }
//         // }
//         // for(auto ele : temp){
//         //     q.push(ele);
//         // }
//         for(auto it = s.begin();it != s.end();it++){
//             pair<int,int> p = *it;
//             if(p.second <= i + a[i]){
//                 if(p.first == INT_MAX-2) break;
//                 dp[i] = 1 + p.first;
//                 break;
//             }
//         }
//         // q.push({dp[i],i});
//         s.insert({dp[i],i});
//     }
//     return (dp[0] == INT_MAX-2) ? -1 : dp[0]; 
// }
