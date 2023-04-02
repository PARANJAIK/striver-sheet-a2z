// Q) Fractional Knapsack -> https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=fractional-knapsack

    // Ans) My approach : 
    
    // NOTE :  IN THIS QUESTION FIRST I TRIED WITH PRIORITY QUEUE AND THAT DIDINT WORK, DONT KNOW WHY ?
    
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        // priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        vector<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            double f = ((double)(arr[i].value)/(arr[i].weight));
            pq.push_back({f,i});
        }
        sort(pq.begin(),pq.end());
        double ans = 0;
        while(!pq.empty() && w > 0){
            auto e = pq.back();
            pq.pop_back();
            int ind = e.second;
            if(arr[ind].weight <= w){
                ans += (double)arr[ind].value;
                w = w - arr[ind].weight;
            }
            else{
                ans += (e.first)*w;
                w = 0;
            }
        }
        return ans;
    }