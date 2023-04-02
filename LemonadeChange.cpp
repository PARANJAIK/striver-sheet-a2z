 // Q) Lemonade Change -> https://leetcode.com/problems/lemonade-change/description/

    // Ans) 

    // i) 

    // bool lemonadeChange(vector<int>& bills) {
    //     int has = 0;
    //     int n = bills.size();
    //     unordered_map<int,int> m = {{5,0},{10,0},{20,0}};
    //     for(int i=0;i<n;i++){
    //         int change = bills[i] - 5;
    //         m[bills[i]]++;
    //         while(m[10] > 0 && change >= 10){
    //             m[10]--;
    //             change -= 10;
    //         }
    //         while(m[5]>0 && change >= 5){
    //             m[5]--;
    //             change -= 5;
    //         }
    //         if(change > 0) return false;
    //     }
    //     return true;
    // }

    // ii) 

    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            if (bill == 10) {
                if (five <= 0) return false;
                ten++;
                five--;
            }
            if (bill == 20) {
                if (five > 0 && ten > 0) {
                    five--;ten--;
                    twenty++; 
                } else if (five >= 3) {
                    five -= 3;
                    twenty++; 
                } else return false;
            }
        }
        return true;
    }