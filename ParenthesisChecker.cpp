// Q) Parenthesis Checker -> https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=parenthesis-checker

    // Ans) 
    
    // i) My simple Stack Approach : 
    
    bool ispar(string s)
    {
        // Your code here
        int n = s.size();
        stack<char> king;
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                king.push(s[i]);
            }
            else{
                if(s[i] == ')'){
                    if(!king.empty() && king.top() == '(') king.pop();
                    else return false;
                }
                if(s[i] == ']'){
                    if(!king.empty() && king.top() == '[') king.pop();
                    else return false;
                }
                if(s[i] == '}'){
                    if(!king.empty() && king.top() == '{') king.pop();
                    else return false;
                }
            }
        }
        if(king.empty()) return true;
        else return false;
    }