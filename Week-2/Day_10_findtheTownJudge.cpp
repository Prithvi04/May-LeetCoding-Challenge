class Solution {
public:
    //use hashmap give +1 if your followed and -1 if you are following someone.
    //traverse through hashmap if any value is N-1, then return the key value ELSE return -1,saying no judge present.
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N<=1)
            return 1;
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++)
        {
            mp[trust[i][0]]--;
            mp[trust[i][1]]++;
        }
        int x=-1;
        //int y=0;
        for(auto it:mp)
        {
            if(it.second==N-1)
                x=it.first;
        }
        return x;
     
        
    }
};