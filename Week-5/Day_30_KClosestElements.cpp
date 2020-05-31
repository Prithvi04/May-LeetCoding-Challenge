#define vi vector<int>
#define piv pair<int,vi>

//overall time complexity O(N + KlogN)

class Solution {
    int find_dist(vector<int> &point){
        //ignoring sqrt of eucledian distance as in effect it is same
        return point[0]*point[0] + point[1]*point[1];     
    }
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        
        vector<piv> dist(n);
        
        for(int i=0;i<n;i++){
            dist[i] = {find_dist(points[i]),points[i]}; 
        }
        
        priority_queue<piv,vector<piv>,greater<piv>> pq(greater<piv>(),dist); // O(N) time complexity
        
        vector<vector<int>> ans;
        
        while(k--){
            piv temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        
        return ans;
        
    }
    
//     multimap<int,int> m;
//     for(int i=0; i<points.size();i++)
//     m.insert({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
//     vector<vector<int>>v;
//     for(auto it=m.begin();K>0;it++,K--) 
//     v.push_back(points[it->second]);
//     return v;
    
};
