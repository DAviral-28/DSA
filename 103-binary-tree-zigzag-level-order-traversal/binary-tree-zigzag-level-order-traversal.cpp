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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==nullptr)
        return v;
        queue<TreeNode*>q;
        q.push(root);
        int flag=false;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>vv;
            for(int i=0;i<n;i++)
                {
                    TreeNode* p=q.front();
                    q.pop();
                    vv.push_back(p->val);
                    if(p->left)
                    q.push(p->left);
                    if(p->right)
                    q.push(p->right);
                }
            if(flag==true)
            reverse(vv.begin(),vv.end());
            flag=!flag;
            v.push_back(vv);
        }
        return v;
    }
};