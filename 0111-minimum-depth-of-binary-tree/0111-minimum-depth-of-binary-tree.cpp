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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return {};
        }
         vector<vector<int>>ans;
         int depth=1;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            vector<int>nums;
            for(int i=q.size();i>0;i--){
            TreeNode*curr=q.front();
            q.pop();
            nums.push_back(curr->val);
            if(curr->left==NULL&&curr->right==NULL){
                return depth;
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            depth++;
            ans.push_back(nums);

        }
        return depth;
    }
};