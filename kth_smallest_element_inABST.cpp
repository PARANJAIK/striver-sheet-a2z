// Q) Delete Node in a BST -> https://leetcode.com/problems/delete-node-in-a-bst/submissions/
    // Ans)
    // i) My Recursive Approach : 

    TreeNode* deleteNode(TreeNode* root,int key){
        if(root==NULL) return root;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(!root->left && !root->right){
                return NULL;
            }
            else if(!root->left || !root->right){
                return root->left ? root->left : root->right;
            }
            else{
               TreeNode* cur = root->left;
               while(cur->right!=NULL){
                   cur = cur->right;
               }
               root->val = cur->val;
               root->left = deleteNode(root->left,cur->val);
            }
        }
        return root;
    }

    // ii) Strivers approach : 

    // TreeNode* deleteNode(TreeNode* root,int key){
    //     if(root==NULL){
    //         return NULL;
    //     }
    //     if(root->val == key){
    //         return helper(root);
    //     }
    //     TreeNode* dummy = root;
    //     while(root!=NULL){
    //         if(root->val > key){
    //             if(root->left!=NULL && root->left->val == key){
    //                 root->left = helper(root->left);
    //                 break;
    //             }
    //             else{
    //                 root = root->left;
    //             }
    //         }
    //         else{
    //             if(root->right!=NULL && root->right->val == key){
    //                 root->right = helper(root->right);
    //                 break;
    //             }
    //             else{
    //                 root = root->right;
    //             }
    //         }
    //     }
    //     return dummy;
    // }

    // TreeNode* helper(TreeNode* root){
    //     if(root->left == NULL){
    //         return root->right;
    //     }
    //     else if(root->right == NULL){
    //         return root->left;
    //     }
    //     TreeNode* rightChild = root->right;
    //     TreeNode* lastRight = findLastRight(root->left);
    //     lastRight->right = rightChild;
    //     return root->left;
    // }

    // TreeNode* findLastRight(TreeNode* root){
    //     if(root->right == NULL){
    //         return root;
    //     }
    //     return findLastRight(root->right);
    // }