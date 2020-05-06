class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //a simple solutions using hashmap
        int res=INT_MIN;
        int a;
        unordered_map<int,int>mp;
        for(int i:nums)
        {
            mp[i]++;
            if(mp[i]>res)
            {
                res=mp[i];
                a=i;
            }
        }
        return a;
        
    }
};