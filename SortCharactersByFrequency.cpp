// Q) Sort Characters By Frequency -> https://leetcode.com/problems/sort-characters-by-frequency/description/

    // Ans)

    // i) My approach : 

    // NOTE : To sort the map by value we took it into a vector

    static bool comp(pair<char,int>& a,pair<char,int>& b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char,int> m;
        int n = s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        vector<pair<char,int>> v;
        for(auto it : m){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),comp);
        int i = 0;
        for(auto it : v){
            int x = it.second;
            while(x--){
                s[i] = it.first;
                i++;
            }
        }
        return s;
    }