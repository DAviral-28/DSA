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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long m=1;
        long long a=0;
        long long b=0;
        while(!q.empty())
        {
            int n=q.size();
            long long ss=q.front().second;
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                long long x=p.second-ss;
                if(i==0)
                a=x;
                if(i==n-1)
                b=x;
                if(node->left)
                q.push({node->left,2*x+1});
                if(node->right)
                q.push({node->right,2*x+2});
            }
            m=max(m,b-a+1);
        }
        return (int)m;
    }
};