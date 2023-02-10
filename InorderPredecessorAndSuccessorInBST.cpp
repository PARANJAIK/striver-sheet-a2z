// Q) Inorder predecessor and successor in BST -> https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// Ans) 

    // Approach : To find the successor we start from the root until the cur pointer becomes NULL, and we see if the
    // cur node can be a successor or not, if it can be a successor, then it means its right cant be a successor, so we 
    // move to the left, and if it cant be the successor it means its left cant be the successor so we move to the right.
    // we do some very similar stuff for predecessor too.

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
pre = NULL;
suc = NULL;
Node* cur = root;
while(cur){
    if(cur->key <= key){
        cur = cur->right;
    }
    else{
        suc = cur;
        cur = cur->left;
    }
}
cur = root;
while(cur){
    if(cur->key >= key){
        cur = cur->left;
    }
    else{
        pre = cur;
        cur = cur->right;
    }
}
return;
}
