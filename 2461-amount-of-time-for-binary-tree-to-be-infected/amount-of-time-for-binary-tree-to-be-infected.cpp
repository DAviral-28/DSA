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
    void mp(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m,TreeNode* &tn,int start)
    {
        if(root==nullptr)
        return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
            if(p->val==start)
            tn=p;
            if(p->left)
            {
                m[p->left]=p;
                q.push(p->left);
            }
            if(p->right)
            {
                m[p->right]=p;
                q.push(p->right);
            }
        }
    }
    int tim(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m)
    {
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(root);
        visited.insert(root);
        int w=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                if(p->left && visited.find(p->left)==visited.end())
                {
                    visited.insert(p->left);
                    q.push(p->left);
                }
                if(p->right && visited.find(p->right)==visited.end())
                {
                    visited.insert(p->right);
                    q.push(p->right);
                }
                if(m.count(p) && visited.find(m[p])==visited.end())
                {
                    visited.insert(m[p]);
                    q.push(m[p]);
                }
            }
            w++;
        }
        return w-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>par;
        TreeNode* tn=NULL;
        mp(root,par,tn,start);
        return tim(tn,par);
    }
};