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
    void ks(TreeNode* root,int k,int &p,int &q)
    {
        if(root==nullptr)
        return;
        ks(root->left,k,p,q);
        p++;
        if(p==k)
        {
            q=root->val;
            return;
        }
        ks(root->right,k,p,q);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr)
        return -1;
        int q;
        int p=0;
        ks(root,k,p,q);
        return q;
    }
};