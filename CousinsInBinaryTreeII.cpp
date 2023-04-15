// Q) Cousins in Binary Tree II -> https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

    // i) My Approach :  

    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) return root;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            vector<pair<TreeNode*,int>> v;
            int sum = 0;
            int index = 0;
            int m = n;
            while(m--){
                pair<TreeNode*,int> p = q.front();
                q.pop();
                v.push_back(p);
                TreeNode* node = p.first;
                sum += node->val;
                if(node->left != NULL){
                    q.push({node->left,index});
                }
                if(node->right != NULL){
                    q.push({node->right,index});
                }
                index++;
            }
            for(int i=0;i<n;i++){
                int parent = v[i].second;
                TreeNode* temp = v[i].first;
                int x = temp->val;
                temp->val = sum - temp->val;
                if(i + 1 < n){
                    if(v[i+1].second == parent){
                        temp->val -= (v[i+1].first)->val;
                        v[i+1].first->val += x;
                    }
                }
            }
        }
        return root;
    }

    // ii) Other's approach : 

    
TreeNode* replaceValueInTree(TreeNode* root) {
    root->val = 0;
    queue<TreeNode*> q;  q.push(root);
    while(!q.empty()){
        int n = q.size(), sum = 0;
        vector<TreeNode*> buf;
        while(n--){
            TreeNode* node = q.front(); q.pop();
            buf.push_back(node);
            if(node->left) { q.push(node->left); sum += node->left->val; }
            if(node->right){ q.push(node->right); sum += node->right->val; }
        }
        for(auto node: buf){
            int  t = sum;
            if(node->left)  t -= node->left->val;
            if(node->right) t -= node->right->val;
            if(node->left)  node->left->val = t;
            if(node->right) node->right->val = t;
        }
    }
    return root;
