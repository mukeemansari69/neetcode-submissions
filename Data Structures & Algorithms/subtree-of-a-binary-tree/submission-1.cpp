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
    bool IsSameTree(TreeNode *p, TreeNode *q){
        if(p==NULL and q==NULL) return true;
        if(p==NULL or q==NULL ) return false ;
        if(p->val != q->val ) return false;
        bool left=IsSameTree(p->left,q->left);
        bool right=IsSameTree(p->right,q->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL ) return false;
        if(root->val==subRoot->val && IsSameTree(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
