// Q) Online Stock Span -> https://leetcode.com/problems/online-stock-span/description/

    // Ans) 

    // i) My initial approach : (WORKS BUT NOT BEST)(NOT BEST BECAUSE I USED A VARIABLE IND, AND WE CAN DO WITHOUT THAT).

    stack<pair<int,int>> king;
    int ind =-1;

    StockSpanner() {
        while(!king.empty()) king.pop();
        ind = -1;
    }
    
    int next(int price) {
        ind++;
        while(!king.empty() && king.top().first <= price){
            king.pop();
        }
        int ans;
        if(king.empty()) ans = ind - (-1);
        else ans = ind - king.top().second;
        king.push({price,ind});
        return ans;
    }

    // ii) BEST APPROACH :

    stack<pair<int, int>> s;

    StockSpanner(){
        
    }

    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }