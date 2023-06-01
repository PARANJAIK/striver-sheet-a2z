// Q) Valid BST from Preorder -> https://www.interviewbit.com/problems/valid-bst-from-preorder/

// Ans) 

// i) My NGE approach : 

bool mysolve(int start,int end,vector<int>& a,int bound,vector<int>& nge){
    if(start > end) return true;
    if(start == end){
        return (a[start] > bound);
    }
    int ind = nge[start];
    if(a[start] <= bound) return false;
    bool left = mysolve(start+1,ind-1,a,bound,nge);
    bool right = mysolve(ind,end,a,a[start],nge);
    return (left && right);
}

int Solution::solve(vector<int>& a){
    int n = a.size();
    vector<int> nge(n);
    nge[n-1] = n;
    stack<pair<int,int>> s;
    s.push({a[n-1],n-1});
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && a[i] > s.top().first){
            s.pop();
        }
        if(s.empty()){
            nge[i] = n;
        }
        else{
            nge[i] = s.top().second;
        }
        s.push({a[i],i});
    }
    return mysolve(0,n-1,a,0,nge);
}

// ii) My Segment Tree approach : 

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

bool mysolve(vector<int>& a,int n,int start,int end,vector<int>& seg,vector<int>& nge){
    if(start >= end) return true;
    int index = nge[start];
    int minn = query(0,0,n-1,index,end,seg);
    if(minn > a[start]){
        bool x = mysolve(a,n,start+1,index-1,seg,nge);
        bool y = mysolve(a,n,index,end,seg,nge);
        return (x && y);
    }
    else{
        return false;
    }
}

int Solution::solve(vector<int> &a) {
    int n = a.size();
    vector<int> seg(4*n,-1);
    segtree(0,0,n-1,a,seg);
    int start = 0,end = n-1;
    vector<int> nge(n);
    nge[n-1] = n;
    stack<pair<int,int>> s;
    s.push({a[n-1],n-1});
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && a[i] > s.top().first){
            s.pop();
        }
        if(s.empty()){
            nge[i] = n;
        }
        else{
            nge[i] = s.top().second;
        }
        s.push({a[i],i});
    }
    return mysolve(a,n,start,end,seg,nge);
}

// iii) Other's stack solution : (I AM NOT ABLE TO UNDERSTAND) : 

int Solution::solve(vector<int> &A) {
   
    stack<int> st;
    int root=-1e9;
    for(auto curr : A){
       
        while(st.size()>0 and curr >=st.top()){
            root=st.top();
            st.pop();
        }
       
        if(root>=curr) return false;
       
        st.push(curr);
    }
    return true;
   
}
