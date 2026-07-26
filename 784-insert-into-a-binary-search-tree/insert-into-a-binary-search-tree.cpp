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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
        {
            root=new TreeNode(val);
            return root;
        }
        TreeNode* temp=root;
        TreeNode* nn=new TreeNode(val);
        while(temp)
        {
            if(temp->val<val && temp->right==nullptr)
            {
                temp->right=nn;
                return root;
            }
            else if(temp->val>val && temp->left==nullptr)
            {
                temp->left=nn;
                return root;
            }
            else if(temp->val<val)
            temp=temp->right;
            else if(temp->val>val)
            temp=temp->left;
        }
        return root;
    }
};