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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "#,";
        string s=to_string(root->val)+",";
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }
   TreeNode * build(string & data, int & i){
      string temp="";
      while(i<data.size()&& data[i]!=','){
        temp+=data[i];
        i++;
      }
      // skip the , 
      i++;
      if(temp=="#") return NULL;
      TreeNode * root= new TreeNode(stoi(temp));
      root->left=build(data,i);
      root->right=build(data,i);
      return root;
   }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
     return  build(data,i);
        
    }
};
