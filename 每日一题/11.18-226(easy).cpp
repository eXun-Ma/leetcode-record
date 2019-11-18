class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode *p=root->right;
        root->right=root->left;
        root->left=p;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
