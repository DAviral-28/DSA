/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mp(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m)
    {
        if(root==nullptr)
        return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
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
    vector<int> dk(TreeNode* root,int k,unordered_map<TreeNode*,TreeNode*>&m)
    {
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(root);
        visited.insert(root);
        int d=0;
        while(!q.empty())
        {
            if(d==k)
            break;
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
            d++;
        }
        vector<int>v;
        while(!q.empty())
        {
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        mp(root,parent);
        return dk(target,k,parent);
    }

};