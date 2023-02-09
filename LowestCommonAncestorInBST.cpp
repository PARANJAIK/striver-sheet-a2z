// Q) Lowest Common Ancestor in BST -> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

    // Ans) Approach : Since it is a BST we can find where p and q are present. So we check if p and q, both are present in the left subtree, then we recursively call the function on root->left. If p and q both are present in the right subtree, then we recursively call the function on root->right. Else case it means that there is a split, so thats the lowest common ancestor of p and q. so here we return root.

    // i) My initial approach (WORKS BUT NOT RECOMMENDED) : 

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(root == NULL || root == p || root == q){
    //         return root;
    //     }
    //     TreeNode* left=NULL,*right=NULL;
    //     // can p or q be present in the left subtree
    //     if(p->val < root->val || q->val < root->val){
    //         left = lowestCommonAncestor(root->left,p,q);
    //     }
    //     // can p or q be present in the right subtree
    //     if(root->val < p->val || root->val < q->val){
    //         right = lowestCommonAncestor(root->right,p,q);
    //     }
    //     if(left == NULL){
    //         return right;
    //     }
    //     else if(right == NULL){
    //         return left;
    //     }
    //     else{
    //         return root;
    //     }
    // }

    // ii) Striver's approach : 

    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL){
            return root;
        }
        int cur = root->val;
        if(p->val < cur && q->val < cur){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(cur < p->val && cur < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }