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
    void path(TreeNode* root, int targetSum, vector<int>&curr,vector<vector<int>>&ans) {
        if(root==NULL){
            return;
        }
        curr.push_back(root->val);
        targetSum=targetSum-root->val;
        if(root->left==NULL&&root->right==NULL&&targetSum==0){
            ans.push_back(curr);
        }
        path(root->left,targetSum,curr,ans);
        path(root->right,targetSum,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
         vector<int>curr;
         vector<vector<int>>ans;
         path(root,targetSum,curr,ans);
         return ans;
    }
};