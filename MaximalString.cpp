// Q) Maximal string -> https://www.interviewbit.com/problems/maximal-string/

// Ans) 

// i) My approach :

void sol(int index,string& s,int b,string& ans){
    int n = s.size();
    if(s > ans) ans = s;
    if(index == n || b == 0){
        if(s > ans) ans = s;
        return;
    }
    int maxx = -1;
    vector<int> indices;
    for(int i = index;i<n;i++){
        if(s[i] - 48 == maxx){
            indices.push_back(i);
        }
        else if(s[i] - 48 > maxx){
            indices.clear();
            maxx = s[i] - 48;
            indices.push_back(i);
        }
    }
    if(maxx == s[index]-48){
        sol(index+1,s,b,ans);
        return;
    }
    for(auto j : indices){
        swap(s[index],s[j]);
        sol(index+1,s,b-1,ans);
        swap(s[index],s[j]);
    }
    return;
}

string Solution::solve(string s,int b){
    int n = s.size();
    string ans;
    sol(0,s,b,ans);
    return ans;
}

