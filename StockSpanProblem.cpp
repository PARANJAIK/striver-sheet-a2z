 // Q) Stock Span Problem -> https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stock-span-problem

    // Ans) 
    
    // i) My approach (PGE) :
    
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> king;
       vector<int> ans;
       for(int i=0;i<n;i++){
           while(!king.empty() && price[king.top()] <= price[i]){
            king.pop();
        }
        if(king.empty()) ans.push_back(i+1);
        else ans.push_back(i-king.top());
        king.push(i);
       }
       return ans;
    }
