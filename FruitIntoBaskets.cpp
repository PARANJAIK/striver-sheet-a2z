//   Q) Fruit into Baskets -> https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

//   Ans) 

//   i) My approach : 
  
  int totalFruits(int n, vector<int> &fruits) {
        unordered_map<int,int> m;
        int i = 0,j=0;
        int ans = 0;
        while(j<n){
            if(m.size() < 2){
                m[fruits[j]]++;
                j++;
            }
            else if(m.size() == 2){
                if(m.find(fruits[j]) == m.end()){
                    ans = max(ans,j-i);
                    while(m.size() == 2){
                    m[fruits[i]]--;
                    if(m[fruits[i]] == 0) m.erase(fruits[i]);
                    i++;
                    }
                    m[fruits[j]]++;
                    j++;
                }
                else{
                    m[fruits[j]]++;
                    j++;
                }
            }
        }
        ans = max(ans,j-i);
        return ans;
    }
    
    // ii) My slight better implementation:
    
    // int totalFruits(int n, vector<int> &fruits) {
    //     unordered_map<int,int> m;
    //     int i = 0,j=0;
    //     int ans = 0;
    //     while(j<n){
    //         if(m.size() < 2){
    //             m[fruits[j]] = j;
    //             j++;
    //         }
    //         else if(m.size() == 2){
    //             if(m.find(fruits[j]) == m.end()){
    //                 ans = max(ans,j-i);
    //                 i = n;
    //                 for(auto it : m){
    //                     i = min(it.second + 1,i);
    //                 }
    //                 for(auto it : m){
    //                     if(it.second == i-1){
    //                         m.erase(it.first);
    //                         break;
    //                     }
    //                 }
    //                 m[fruits[j]] = j;
    //                 j++;
    //             }
    //             else{
    //                 m[fruits[j]] = j;
    //                 j++;
    //             }
    //         }
    //     }
    //     ans = max(ans,j-i);
    //     return ans;
    // }
