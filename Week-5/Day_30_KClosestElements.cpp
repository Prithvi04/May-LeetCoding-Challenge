class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //Heap Approach whose time complexity is O(NlogK)- best approach  i feel, but it passes 70/81 testcases due to some reason
        //Might be a leetcode mistake.
        /*priority_queue<vector<int>>q;
        int i=0;
        while(i<K)
        {
            q.push({points[i][0],points[i][1]});
            i++;
        }
        vector<vector<int>>res;
        while(i<points.size())
        {
            vector<int>temp=q.top();
            int dis1=sqrt(pow(temp[0],2)+pow(temp[1],2));
            int dis2=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            if(dis2<dis1)
            {
                q.pop();
                q.push(points[i]);
                i++;
            }
            else
                i++;
            
        }
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;*/

//Multimap Approach whos time complexity is O(NlogN) , second best approach according to me.
         multimap<int,int> m;
         for(int i=0; i<points.size();i++)
         m.insert({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
         vector<vector<int>>v;
         for(auto it=m.begin();K>0;it++,K--) 
         v.push_back(points[it->second]);
         return v;
        
        
    }
};