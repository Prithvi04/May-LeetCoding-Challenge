class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        unordered_map<int,int>mp;
        int pre_sum=0,res=0;
        for(int i=0;i<nums.size();i++)
        {
            pre_sum+=nums[i];
            if(pre_sum==0)
                res=i+1;
            if(mp.find(pre_sum)==mp.end())
                mp.insert({pre_sum,i});
            if(mp.find(pre_sum-0)!=mp.end())
                res=max(res,i-mp[pre_sum-0]);
                
        }
        return res;
        
    }
};
//Trick is to convert all 0 to -1
// That will convert it to a problem of largest substring with sum equal to 0.