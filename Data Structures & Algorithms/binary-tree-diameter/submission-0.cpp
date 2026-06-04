
class Solution {
public:
    int level(TreeNode * root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void helper(TreeNode * root, int &maxdia){
        if(root==NULL) return ;
        int left=level(root->left);
        int right=level(root->right);
        maxdia=max(maxdia,left+right);
        helper(root->left,maxdia);
        helper(root->right,maxdia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxdia=INT_MIN;
        helper(root,maxdia);
        return maxdia;
    }
};
