// Q) Largest BST -> https://practice.geeksforgeeks.org/problems/largest-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-bst

    // Ans) 
    
    // i) My approach : The approach is that when i am at a node, i see whether the left subtree and right subtree are valid BST or not, if both of them are valid BST then i will check whether the whole tree is a valid BST or not. If the whole tree is a valid BST then we return true with the size of the tree, else if the tree is not a valid BST, we return a false with max of largest BST size in both the subtrees. If both of the subtrees are not BST's, then we return false with max of largest BST of both the subtrees.
    
    // int largestBst(Node *root)
    // {
    // 	//Your code here
    // 	if(root==NULL) return 1;
    // 	pair<bool,int> p = solve(root);
    // 	return p.second;
    // }
    
    // pair<bool,int> solve(Node* root){
    //     // pair<bool,int> ans;
    //     // ans = {true,1};
    //     if(root==NULL) return {true,0};
    //     pair<bool,int> p,q;
    //     p = solve(root->left);
    //     q = solve(root->right);
    //     if(p.first && q.first){
    //         Node* maxx=NULL,*minn=NULL;
    //         if(root->left) minn = root->left;
    //         while(minn && minn->right!=NULL){
    //             minn = minn->right;
    //         }
    //         if(root->right) maxx = root->right;
    //         while(maxx && maxx->left!=NULL){
    //             maxx = maxx->left;
    //         }
    //         if(minn && (root->data <= minn->data)){
    //             return {false,max(p.second,q.second)};
    //         }
    //         else if(maxx && (maxx->data <= root->data)){
    //             return {false,max(p.second,q.second)};
    //         }
    //         else{
    //             return {true,p.second+q.second+1};
    //         }
    //     }
    //     else return{false,max(p.second,q.second)};
    // }
    
    // ii) Striver's approach : Similar to my approach , but sir had maintained the largest and smallest node in the subtrees while traversing , so that there is no need to run the while loops again for finding them.
    
    // class Nodevalue{
    //     public: 
    //           int maxnode,minnode,maxsize;
    //           Nodevalue(int minnode,int maxnode,int maxsize){
    //               this->maxnode = maxnode;
    //               this->minnode = minnode;
    //               this->maxsize = maxsize;
    //           }
    // };
    
    // class Solution{
    //     private:
    //          Nodevalue largestBSTSubtreeHelper(Node* root){
    //              if(!root){
    //                  return Nodevalue(INT_MAX,INT_MIN,0);
    //              }
                 
    //              auto left = largestBSTSubtreeHelper(root->left);
    //              auto right = largestBSTSubtreeHelper(root->right);
                 
    //              if(left.maxnode < root->data && root->data < right.minnode){
    //                  return Nodevalue(min(root->data,left.minnode),max(root->data,right.maxnode),left.maxsize + right.maxsize + 1);
    //              }
    //              return Nodevalue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
    //          }
             
    //   public:
    //         int largestBst(Node* root){
    //             return largestBSTSubtreeHelper(root).maxsize;
    //         }
    // };