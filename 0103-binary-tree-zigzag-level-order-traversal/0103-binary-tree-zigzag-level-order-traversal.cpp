/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      
        vector<vector<int>>res;
        if(!root)return res;
        bool flag=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          vector<int>lev(size);
          for(int i=0;i<size;i++){
            TreeNode* vall=q.front();
            q.pop();
            if(flag){
                lev[i]=vall->val;
            }else{
                lev[size-i-1]=vall->val;
            }
            if(vall->left){
                q.push(vall->left);
            }
            if(vall->right){
                q.push(vall->right);
            }
          }
          res.push_back(lev);
            flag=(!flag);
        }
        return res;
    }
};