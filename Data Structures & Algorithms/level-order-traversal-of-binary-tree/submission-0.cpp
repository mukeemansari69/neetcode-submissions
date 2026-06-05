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
    int level(TreeNode * root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void helper(TreeNode * root, int curr, int target,vector<int>&v){
        if(root==NULL){
            return ;
        }
        if(curr==target){
            v.push_back(root->val);
        }
        helper(root->left,curr+1,target,v);
        helper(root->right,curr+1,target,v);

    }
    void traversal(TreeNode * root, vector<vector<int>>&ans){
        if(root==NULL) return ;
        int n=level(root);
        for(int i=0;i<n;i++){
            vector<int>v;
            helper(root,0,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         if(root==NULL) return ans;
        traversal(root,ans);
        return  ans;

        
    }
};
