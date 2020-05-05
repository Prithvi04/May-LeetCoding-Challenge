class Solution {
public:
    int firstUniqChar(string s) {
        //The approach is to use a hashmap to store index of the character, if the character repeats then change the value to -1.
        //traverse the hashmap and return the lowest index, if all index are -1 then return -1.
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end())
                mp[s[i]]=-1;
            else
                mp.insert({s[i],i});
        }
        int mini=INT_MAX;
        for(auto it:mp)
        {
            if(it.second!=-1)
                mini=min(mini,it.second);
        }
        if(mini!=INT_MAX)
            return mini;
        else
            return -1;
        
    }
};