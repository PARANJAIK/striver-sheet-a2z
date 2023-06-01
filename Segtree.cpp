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
