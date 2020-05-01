// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    //Optimal way is to use Binary Search.
    int firstBadVersion(int n) {
        int mid=-1;
        int l=1,u=n;
        //int flag=true;
        
        while(l<u)
        {
            mid=l+floor((u-l)/2); //floor value 
            if(isBadVersion(mid))
            {
                u=mid;
            }
            else
            {
                l=mid+1;
            }
        }

        return l;//least value i.e first bad version
    }
};