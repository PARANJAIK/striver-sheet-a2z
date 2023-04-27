// Q) Gray code -> https://www.interviewbit.com/problems/gray-code/

// Ans)

// i) my approach : 

// vector<int> Solution::grayCode(int n) {
//     if(n == 1) return {0,1};
//     vector<string> v;
//     v.push_back("0");
//     v.push_back("1");
//     for(int i=0;i<n-1;i++){
//         int size = v.size();
//         for(int j=size-1;j>=0;j--){
//             v.push_back(v[j]);
//         }
//         for(int j=0;j<size;j++){
//             v[j].push_back('0');
//             v[v.size()-1-j].push_back('1');
//         }
//     }
//     vector<int> ans;
//     for(auto s : v){
//         int size = s.size();
//         int temp = 0;
//         for(int i=0;i<size;i++){
//             if(s[i] == '1') temp += (1<<i);
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }

// ii) using bit manipulation :

// vector<int> Solution::grayCode(int temp) {
// vector<int> ans;
// int sz = 1<<temp;
// for(int a=0;a<(sz);a++){
// ans.push_back(a ^ (a>>1));
// }
// return ans;
// }

// iii) recursive approach : (BEST APPROACH):

void solve(int bit, vector<int> &ans, int& cur) {
    if(bit < 0) {
        ans.push_back(cur);
        return;
    }
    solve(bit-1, ans, cur);
    cur ^= (1 << bit); // flip this bit
    solve(bit-1, ans, cur);
}

vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    int cur = 0;
    solve(A-1, ans, cur);
    return ans;
}
