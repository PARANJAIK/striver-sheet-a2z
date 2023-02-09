// Q) Kth smallest Element in a BST -> https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

    // Ans) Approach : Just do a simple inorder and print the k-1 th element, but dont store the inorder, because it will need some extra space. If we have to find kth largest element we need to 
    // first do a O(n) traversal to find the total no.of nodes and then we find the (n-k)th smallest element.

    // code:

    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        int cnt = 0;
        return inorder(root,cnt,k);
    }

    int inorder(TreeNode* root,int& cnt,int& k){
        if(root==NULL) return -1;
        int x = inorder(root->left,cnt,k);
        if(x!=-1){
            return x;
        }
        cnt++;
        if(cnt == k){
            return root->val;
        }
        x = inorder(root->right,cnt,k);
        if(x!=-1){
            return x;
        }
        return -1;
    }
