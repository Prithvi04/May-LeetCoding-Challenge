class Solution {
public:
    //solution using two hashmaps for both characters in both string and finally doing a comparison of both strings
    //Can be more space optimized
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;
        for(char ch:ransomNote)
        mp1[ch]++;
        
        unordered_map<char,int>mp2;
        for(char ch:magazine)
            mp2[ch]++;
        
        for(auto it:mp1)
        {
            if(mp2.find(it.first)!=mp2.end())
            {
                if(mp2[it.first]<mp1[it.first])
                    return false;
            }
            else
                return false;
            
        }
        return true;
    }
};