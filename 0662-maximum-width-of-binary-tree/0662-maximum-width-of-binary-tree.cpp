class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second; // minimum id in this level
            long long first = 0, last = 0;
            
            for (int i = 0; i < size; i++) {
                long long id = q.front().second - mmin;  // normalize
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) first = id;
                if (i == size - 1) last = id;
                
                // children use normalized id (safe from overflow)
                if (node->left)  q.push({node->left, 2 * id + 1});
                if (node->right) q.push({node->right, 2 * id + 2});
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};
