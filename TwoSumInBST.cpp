// Q) Two Sum in BST -> https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

    // Ans) 

    // i) My approach : 

    // bool findTarget(TreeNode* root, int k) {
    //     unordered_map<int,int> m;
    //     return inorder(root,k,m);
    // }
    
    // bool inorder(TreeNode* root,int k,unordered_map<int,int>& m){
    //     if(root==NULL) return false;
    //     bool x = inorder(root->left,k,m);
    //     if(x) return true;
    //     if(m[k-root->val]!=0) return true;
    //     else{
    //         m[root->val] = 1;
    //     }
    //     x = inorder(root->right,k,m);
    //     return x;
    // }

    // ii) Striver's TWO SUM APPROACH (USING BST iterator) : 
 
    class BSTIterator{
        stack<TreeNode*> myStack;
        //reverse -> true -> before
        // reverse -> false -> next
        bool reverse = true;

        public : 
            BSTIterator(TreeNode* root,bool isReverse){
                reverse = isReverse;
                pushAll(root);
            }

            bool hasNext(){
                return !myStack.empty();
            }

            int next(){
                TreeNode* tmpNode = myStack.top();
                myStack.pop();
                if(!reverse) pushAll(tmpNode->right);
                else pushAll(tmpNode->left);
                return tmpNode->val;
            }

        private : 
            void pushAll(TreeNode* node){
                for(;node!=NULL;){
                    myStack.push(node);
                    if(reverse == true){
                        node = node->right;
                    }
                    else{
                        node = node->left;
                    }
                }
            }
    };

    class Solution{
        public : 
           bool findTarget(TreeNode* root,int k){
               if(!root) return false;
               BSTIterator l(root,false);
               BSTIterator r(root,true);
               int i = l.next();
               int j = r.next();
               while(i<j){
                   if(i+j == k) return true;
                   else if(i+j < k) i = l.next();
                   else j = r.next();
               }
               return false;
           }
    };