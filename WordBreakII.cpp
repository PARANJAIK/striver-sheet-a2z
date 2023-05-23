 // Q) Word Break II -> https://leetcode.com/problems/word-break-ii/description/

    // Ans) 

    // i) The optimal approach using Trie Data structure :

    // NOTE :  We can even do this using map or set , but Trie gives the best time complexity. 
   
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

    vector<string> wordBreak(string s, vector<string>& wordDict){
        string temp = s;
        vector<string> ans;
        Trie* obj = new Trie();
        for(int i=0;i<wordDict.size();i++){
            obj->insert(wordDict[i]);
        }
        solve(s,temp,obj,1,0,0,ans);
        return ans;
    }
 
    void solve(string& s,string& temp,Trie* obj,int ind,int cnt,int preind,vector<string>& ans){
        if(ind == s.size()){
            if(check(preind,ind,s,obj)){
                ans.push_back(temp);
            }
            return;
        }
        // i dont insert a space here
        solve(s,temp,obj,ind+1,cnt,preind,ans);
        // checking if we can insert a space here
        if(check(preind,ind,s,obj)){
            temp.insert(ind+cnt," ");
            solve(s,temp,obj,ind+1,cnt+1,ind,ans); // inserting space if we can
            temp.erase(ind+cnt,1);
        }
        return;
    }

    bool check(int preind,int ind,string& s,Trie* obj){
        string word = s.substr(preind,ind-preind);
        return obj->search(word);
    }   

    //  ii) Initial good approach without using any map,set or Trie : 

     // vector<string> wordBreak(string s, vector<string>& wordDict){
    //     string temp = s;
    //     vector<string> ans;
    //     solve(s,temp,wordDict,1,0,0,ans);
    //     return ans;
    // }
 
    // void solve(string& s,string& temp,vector<string>& wordDict,int ind,int cnt,int preind,vector<string>& ans){
    //     if(ind == s.size()){
    //         if(check(preind,ind,s,wordDict)){
    //             ans.push_back(temp);
    //         }
    //         return;
    //     }
    //     // i dont insert a space here
    //     solve(s,temp,wordDict,ind+1,cnt,preind,ans);
    //     // checking if we can insert a space here
    //     if(check(preind,ind,s,wordDict)){
    //         temp.insert(ind+cnt," ");
    //         solve(s,temp,wordDict,ind+1,cnt+1,ind,ans); // inserting space if we can
    //         temp.erase(ind+cnt,1);
    //     }
    //     return;
    // }

    // bool check(int preind,int ind,string& s,vector<string>& wordDict){
    //     string temp = s.substr(preind,ind-preind);
    //     int n = wordDict.size();
    //     bool found = false;
    //     for(int i=0;i<n;i++){
    //         if(temp == wordDict[i]){
    //             found = true;
    //             break;
    //         } 
    //     }
    //     return found;
    // }
