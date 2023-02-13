// Q) Merge Two BST's -> https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-two-bst-s
    
    // Ans) 
    
    // i) Brute force approach : Do seperate inorder traversals for both the BST's and store them, then merge
    //   the two sorted arrays to get the final sorted array which is obvious.
       
    // ii) Optimal Approach : (Simultaneous Inorder traversal) for both the BST's. Here we do inorder for both the
        // trees simultaneously using two stacks, and in the process generate the required sorted array. So here
        // we reduce the need of extra space for storing the inorders and reduce the time too probably.
    
    // CODE :
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       stack<Node*> s1,s2;
       while(root1!=NULL){
           s1.push(root1);
           root1 = root1->left;
       }
       while(root2!=NULL){
           s2.push(root2);
           root2 = root2->left;
       }
       while(!s1.empty() && !s2.empty()){
           if(s1.top()->data<=s2.top()->data){
               root1 = s1.top()->right;
               ans.push_back(s1.top()->data);
               s1.pop();
               while(root1!=NULL){
                   s1.push(root1);
                   root1 = root1->left;
               }
           }
           else{
               root2 = s2.top()->right;
               ans.push_back(s2.top()->data);
               s2.pop();
               while(root2!=NULL){
                   s2.push(root2);
                   root2 = root2->left;
               }
           }
       }
       while(!s1.empty()){
           ans.push_back(s1.top()->data);
           root1 = s1.top()->right;
           s1.pop();
           while(root1!=NULL){
               s1.push(root1);
               root1 = root1->left;
           }
       }
       while(!s2.empty()){
           root2 = s2.top()->right;
               ans.push_back(s2.top()->data);
               s2.pop();
               while(root2!=NULL){
                   s2.push(root2);
                   root2 = root2->left;
               }
       }
       return ans;
    }