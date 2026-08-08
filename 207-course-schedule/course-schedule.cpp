class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>adj[numCourses];
        for(int i=0;i<n;i++)
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<int>indegree(numCourses);
        for(int i=0;i<n;i++)
        {
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int p=0;
        while(!q.empty())
        {
            int w=q.front();
            q.pop();
            p++;
            for(int x : adj[w])
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
        return p==numCourses;
    }
};