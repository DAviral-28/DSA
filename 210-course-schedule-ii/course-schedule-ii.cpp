class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            indegree[prerequisites[i][0]]++;
        }
        vector<int>adj[numCourses];
        for(int i=0;i<n;i++)
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        queue<int>q;
        vector<int>v;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            v.push_back(node);
            for(int x : adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
        if(v.size()==numCourses)
        return v;
        return {};
    }
};