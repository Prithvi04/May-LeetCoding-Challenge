class Solution {
public:
	//Since the vector is sorted the code can be optimized from O(N) to O(logN)
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums[0];
        for(int i=1;i<nums.size();i++)
            n=n^nums[i];
        return n;
        
    }
};