// Q) BTS Iterator -> https://leetcode.com/problems/binary-search-tree-iterator/description/

// Ans) i) Solution : 

class BSTIterator {
private:
 stack<TreeNode*> myStack;

 void pushAll(TreeNode* root){
    // while(root!=NULL){
    //     myStack.push(root);
    //     root = root->left;
    // }
    for(;root!=NULL;myStack.push(root),root=root->left);
 }

public:

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};