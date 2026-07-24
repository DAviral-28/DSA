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
    int mps(TreeNode* root,int &s)
    {
        if(root==nullptr)
        return 0;
        int left=mps(root->left,s);
        int right=mps(root->right,s);
        s=max(s,left+right+root->val);
        return max(0,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int s=INT_MIN;
        mps(root,s);
        return s;
    }
};