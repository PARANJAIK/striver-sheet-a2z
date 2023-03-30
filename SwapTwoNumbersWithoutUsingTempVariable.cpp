 // Q) Swap two numbers without using temp variable : 

    pair<int, int> get(int x, int y){
        //complete the function here
        x = x + y;
        y = x - y;
        x = x - y;
        return {x,y};
    }