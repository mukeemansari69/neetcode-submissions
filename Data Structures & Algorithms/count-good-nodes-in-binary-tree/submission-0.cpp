

class Solution {
public:
   void helper(TreeNode * root, int mx,int & count){
    if(root==NULL) return ;
    if(root->val>=mx) count++;
    mx=max(mx,root->val);
    helper(root->left,mx,count);
    helper(root->right,mx,count);
   }
    int goodNodes(TreeNode* root) {
        int count =0;
        helper(root,root->val,count);
        return count;
    }
};
