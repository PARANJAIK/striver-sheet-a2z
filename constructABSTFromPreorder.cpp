// Q) construction of BST from preorder Traversal -> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

    // Ans) 

    // i) My Recursive approach :

        // approach : The first element of preorder is going to be the root, then we call the same function recursively to construct the left subtree with its preorder and assign it to root->left,similar thing to root->right.

    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     return construct(preorder,0,preorder.size()-1);
    // }

    // TreeNode* construct(vector<int>& preorder,int prestart,int preend){
    //     if(prestart > preend) return NULL;
    //     int temp = preorder[prestart];
    //     TreeNode* node = new TreeNode(temp);
    //     int index = prestart;
    //     while(index<=preend && preorder[index]<=temp){
    //         index++;
    //     }
    //     node->left = construct(preorder,prestart+1,index-1);
    //     node->right = construct(preorder,index,preend);
    //     return node;
    // }

    // ii) Striver's recursive approach : 

    // approach : We basically maintain the upperbounds, and check if we can insert a particular element of preorder at that place or not.

    // TreeNode* bstFromPreorder(vector<int>& preorder){
    //     int i = 0;
    //     return build(preorder,i,INT_MAX);
    // }

    // TreeNode* build(vector<int>& preorder,int& i,int bound){
    //     if(i==preorder.size() || preorder[i]>bound) return NULL;
    //     TreeNode* root = new TreeNode(preorder[i++]);
    //     root->left = build(preorder,i,root->val);
    //     root->right = build(preorder,i,bound);
    //     return root;
    // }