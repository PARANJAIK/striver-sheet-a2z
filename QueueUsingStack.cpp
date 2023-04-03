// Q) Queue Using Stack -> https://practice.geeksforgeeks.org/problems/queue-using-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=queue-using-stack

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int dequeue() {
        if(input.empty()) return -1;
        int ans = input.top();
        input.pop();
        return ans;
    }
};