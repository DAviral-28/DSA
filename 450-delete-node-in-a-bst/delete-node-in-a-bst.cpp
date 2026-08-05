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
    TreeNode* lc(TreeNode* root)
    {
        if(root->right==nullptr)
        return root;
        return lc(root->right); 
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->right==nullptr)
        return root->left;
        else if(root->left==nullptr)
        return root->right;
        TreeNode* rc=root->right;
        TreeNode* lr=lc(root->left);
        lr->right=rc;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        return root;
        if(root->val==key)
        return helper(root);
        TreeNode* temp=root;
        while(temp)
        {
        if(temp->val>key)
        {
            if(temp->left && temp->left->val==key)
            {
                temp->left=helper(temp->left);
                break;
            }
            else
            temp=temp->left;
        }
        else
        {
            if(temp->right && temp->right->val==key)
            {
                temp->right=helper(temp->right);
                break;
            }
            else
            temp=temp->right;
        }
        }
        return root;
    }
};