// Q) Recover BST (exactly two nodes swapped) -> https://leetcode.com/problems/recover-binary-search-tree/description/

// Ans) 

// i) INORDER APPROACH : Do a simple inorder traversal, and if any node violates the ascending order, it will be stored in the pointers. This way we have 3 pointers : first,middle and last. After the traversal we swap first and last if possible else we swap first and middle.

// CODE :

private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle,*last;
private:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }

public : 
    void recoverTree(TreeNode* root){
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        // morris(root,first,middle,last,prev);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }

    // ii) MORRIS TRAVERSAL APPROACH : The same method of solving but using MORRIS TRAVERSAL instead of inorder traversal. 

    // NOTE : FAILED

// public:
    // void morris(TreeNode* root,TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev){
    //     TreeNode* cur = root;
    //     // TreeNode* last = NULL;
    //     while(cur!=NULL){
    //        if(cur->left == NULL){
    //            if(prev!=NULL && (cur->val < prev->val)){
    //                if(first==NULL){
    //                    first = prev;
    //                    middle = cur;
    //                }
    //                else{
    //                    last = cur;
    //                }
    //            }
    //            prev = cur;
    //            cur = cur->right;
    //        }
    //        else{
    //            TreeNode* last = cur->left;
    //            while(last->right!=NULL && last->right!=cur){
    //                last = last->right;
    //            }
    //            if(last->right==NULL){
    //                last->right = cur;
    //                cur = cur->left;
    //            }
    //            else{
    //                if(prev!=NULL && (cur->val < prev->val)){
    //                    if(first == NULL){
    //                        first = prev;
    //                        middle = cur;
    //                    }
    //                    else{
    //                        last = cur;
    //                    }
    //                }
    //                prev = cur;
    //                last->right = NULL;
    //                cur = cur->right;
    //            }
    //        }
    //     }
    // }