// Q) All divisors of a Number -> https://practice.geeksforgeeks.org/problems/all-divisors-of-a-number/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=all-divisors-of-a-number

    // Ans)
  
    void print_divisors(int n) {
        // Code here.
        stack<int> s;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                cout<<i<<" ";
                if(i*i != n) s.push(n/i);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        return;
    }