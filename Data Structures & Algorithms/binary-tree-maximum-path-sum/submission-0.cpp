class Solution {
public:
    int helper(TreeNode* root, int sum, int &maxsum) {
        if (root == NULL) return 0;

        // Get best path from left and right (ignore negative paths)
        int left = max(0, helper(root->left, sum, maxsum));
        int right = max(0, helper(root->right, sum, maxsum));

        // Update the global maximum path sum
        maxsum = max(maxsum, root->val + left + right);

        // Return the best single-branch path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        helper(root, 0, maxsum);
        return maxsum;
    }
};
