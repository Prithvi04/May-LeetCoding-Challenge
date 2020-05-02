class Solution {
public:
    //use a hashmap to store the number of occurances of each stone and use the hashmap to count the number of jewels.
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int>mp;
        for(char ch:S)
            mp[ch]++;
        
        int count=0;
        for(char ch:J)
        {
            if(mp.find(ch)!=mp.end())
                count+=mp[ch];
        }
        return count;
    }
};
