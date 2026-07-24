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
    int dbt(TreeNode* root,int &m)
    {
        if(root==nullptr)
        return 0;
        int left=dbt(root->left,m);
        int right=dbt(root->right,m);
        m=max(m,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        return 0;
        int m=0;
        dbt(root,m);
        return m;
    }
};