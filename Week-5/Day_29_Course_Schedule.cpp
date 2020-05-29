class Solution {
public:
    //Treat the relation between each subject as a directed graph
    //We there's a violation between the courses for pre-reqisites, then there should be a cycle formed
    //I'm using topological sort (Khan's BFS Algorithm) to detect the cycle and return the apprpriate bool value.
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        int indegree[numCourses];
        //bool visited[numCourses];
        for(int i=0;i<numCourses;i++)
        {
            indegree[i]=0;
            //visited[i]=false;
        }
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
            
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(q.empty()==false)
        {
            int v=q.front();
            q.pop();
            for(int u:adj[v])
            {
                indegree[u]--;
                if(indegree[u]==0)
                    q.push(u);
                
            }
            count++;
        }
        if(count!=numCourses)
            return false;
        else
            return true;
        
    }
};