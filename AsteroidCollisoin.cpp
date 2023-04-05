// Q) Asteroid Collision -> https://leetcode.com/problems/asteroid-collision/description/

    // Ans) 

    // i) My approach (1st Implementation):

    // vector<int> asteroidCollision(vector<int>& asteroids) {
    //     vector<int> ans;
    //     int n = asteroids.size();
    //     for(int i=0;i<n;i++){
    //         if(asteroids[i] > 0 || ans.empty()) ans.push_back(asteroids[i]);
    //         else{
    //             int x = 1;
    //             while(!ans.empty() && ans.back() > 0){
    //                 if(ans.back() < abs(asteroids[i])){
    //                     ans.pop_back();
    //                 }
    //                 else if(ans.back() == abs(asteroids[i])){
    //                     ans.pop_back();
    //                     x = 0;
    //                     break;
    //                 }
    //                 else{
    //                     x = 0;
    //                     break;
    //                 }
    //             }
    //             if(x) ans.push_back(asteroids[i]);
    //         }
    //     }
    //     return ans;
    // }

    // ii) My slightly better implementation : 

     vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i] > 0 || ans.empty()) ans.push_back(asteroids[i]);
            else{
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])){
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back()>0 && ans.back() == abs(asteroids[i])){
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back()<0){
                    ans.push_back(asteroids[i]);
                }
            }
        }
        return ans;
    }
