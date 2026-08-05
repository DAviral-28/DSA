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
    bool ivb(TreeNode* root,long long l, long long r)
    {
        if(root==nullptr)
        return true;
        if(root->val>=r || root->val<=l)
        return false;
        return ivb(root->left,l,root->val) && ivb(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        return true;
        return ivb(root,LLONG_MIN,LLONG_MAX);
    }
};