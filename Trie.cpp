// Q) Trie implementation -> https://leetcode.com/problems/implement-trie-prefix-tree/description/

// i) Striver's approach : https://www.youtube.com/watch?v=dBGUmUQhjaM&t=1583s

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool contains(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* getlink(char ch){
        return links[ch - 'a'];
    }

    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }    
};

class Trie {
private:
Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!(node->contains(word[i]))){
                node->put(word[i],new Node());
            }
            node = node->getlink(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->getlink(word[i]);
        }
        return (node->isEnd());
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->getlink(prefix[i]);
        }
        return true;        
    }
};

// ii) Other approach (IMPLEMENTATION FAILING DUE TO SOME ERROR) : https://www.youtube.com/watch?v=6PX6wqDQE20&list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl&index=1

// struct Node{
//     Node* links[26];
//     int we = 0;
//     char data;

//     Node(char ch){
//         data = ch;
//         we = 0;
//     }

//     bool contains(char ch){
//         return (links[ch - 'a'] != NULL);
//     }

//     Node* getlink(char ch){
//         return links[ch - 'a'];
//     }

//     void put(char ch){
//         Node* temp = new Node(ch);
//         links[ch - 'a'] = temp;
//     }
// };

// class Trie {
// private:
// Node* root;

// public:
//     Trie() {
//         root = new Node('/');
//     }
    
//     void insert(string word) {
//         Node* node = root;
//         for(int i=0;i<word.size();i++){
//             if(!(node->contains(word[i]))){
//                 node->put(word[i]);
//                 node = node->getlink(word[i]);
//             }
//             else{
//                 // node->put(word[i]);
//                 node = node->getlink(word[i]);
//             }
//             // if(!node->contains(word[i])){
//             //     node->put(word[i]);
//             // }
//             // node = node->getlink(word[i]);
//         }
//         node->we += 1;
//     }
    
//     bool search(string word) {
//         Node* node = root;
//         for(int i=0;i<word.size();i++){
//             if(!node->contains(word[i])){
//                 return false;
//             }
//             node = node->getlink(word[i]);
//         }
//         return (node->we >= 1);
//     }
    
//     bool startsWith(string prefix) {
//         Node* node = root;
//         for(int i=0;i<prefix.size();i++){
//             if(!node->contains(prefix[i])){
//                 return false;
//             }
//             node = node->getlink(prefix[i]);
//         }
//         return true;        
//     }
// };
