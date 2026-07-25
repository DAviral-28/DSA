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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(root==nullptr)
        return v;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>m;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                q.pop();
                int x=p.second.first;
                int y=p.second.second;
                TreeNode* node=p.first;
                m[x][y].insert(node->val);
                if(node->left)
                    q.push({node->left,{x-1,y+1}});
                if(node->right)
                    q.push({node->right,{x+1,y+1}});
            }
        }
       for(auto a :m)
        {
            vector<int>temp;
            for(auto b : a.second)
            {
                temp.insert(temp.end(),b.second.begin(),b.second.end());
            }
            v.push_back(temp);
        }
        return v;
        

    }
};