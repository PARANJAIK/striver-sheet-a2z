// Q) Validate BST -> https://leetcode.com/problems/validate-binary-search-tree/description/

    // Ans) 

    // Approach: My Initial approach is to simply do a inroder traversal and return false if the condition of BST is violated.
    // Striver's approach is to define range for every node value and the range for initial root node is [INT_MIN-1,INT_MAX+1];

    // i) My Inorder approach : 

    // bool isValidBST(TreeNode* root) {
    //     if(root==NULL) return true;
    //     long long int prev = INT_MIN - 1LL;
    //     return inorder(root,prev);
    // }

    // bool inorder(TreeNode* root,long long int& prev){
    //     if(root == NULL) return true;
    //     bool x = inorder(root->left,prev);
    //     if(!x) return false;
    //     if(prev >= root->val){
    //         return false;
    //     }
    //     prev = root->val;
    //     x = inorder(root->right,prev);
    //     if(!x) return false;
    //     return true;
    // }

    // ii) My Recursive apporach (DOES NOT WORK, reason is obvious) : 

    // bool isValidBST(TreeNode* root,int key){
    //     if(root==NULL) return true;
    //     bool x = isValidBST(root->left,root->val);
    //     if(!x) return false;
    //     if(root->left && root->left->val>=root->val) return false;
    //     if(root->right && root->right->val<=root->val) return false;
    //     if(root->val )
    //     x = isValidBST(root->right);
    //     if(!x) return false;
    //     return true;
    // }

    // iii) Striver's Recursive approach (WORKS) :

    bool isValidBST(TreeNode* root){
        return isValidBST(root,INT_MIN-1LL,INT_MAX+1LL);
    }

    bool isValidBST(TreeNode* root,long long int minval,long long int maxval){
        if(root==NULL) return true;
        if(root->val >= maxval || root->val <= minval) return false;
        return isValidBST(root->left,minval,root->val) && isValidBST(root->right,root->val,maxval);
    }