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
    bool is(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr && q==nullptr)
        return true;
        else if(p==nullptr || q==nullptr || p->val!=q->val)
        return false;
        return is(p->left,q->right) && is(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        return true;
        return is(root->left,root->right);
    }
};