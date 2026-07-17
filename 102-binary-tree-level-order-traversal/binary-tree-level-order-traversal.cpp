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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==nullptr)
        return v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        vector<int>vv;
        while(q.size()>1)
        {
            TreeNode* p=q.front();
            q.pop();
            if(p==nullptr)
            {
                q.push(nullptr);
                v.push_back(vv);
                vv.clear();
                continue;
            }
            vv.push_back(p->val);
            if(p->left)
            q.push(p->left);
            if(p->right)
            q.push(p->right);
        }
        v.push_back(vv);
        return v;
    }
};