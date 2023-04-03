// Q) Min Stack -> https://leetcode.com/problems/min-stack/description/
            //  -> https://www.youtube.com/watch?v=V09NfaGf2ao

// Ans)
*/
class MinStack {
public:
    long long int minEle;
    stack<long long> obj;

    MinStack() {
        while(!obj.empty()) obj.pop();
    }
    
    void push(int val) {
        if(obj.empty()){
            minEle = val;
            obj.push(val);
        }
        else{
            if(val < minEle){
               obj.push(2*1LL*val - minEle);
               minEle = val;
            }
            else{
                obj.push(val);
            }
        }
    }
    
    void pop() {
        long long int x = obj.top();
        if(x < minEle){
           long long int val = minEle;
           minEle = 2*val - x;
           obj.pop();
        }
        else{
            obj.pop();
        }
    }
    
    int top() {
        long long int x = obj.top();
        if(x < minEle) return minEle;
        else return x;
    }
    
    int getMin() {
        return minEle;
    }
};