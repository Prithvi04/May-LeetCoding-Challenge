class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>res;
        
        int i=0,j=0;
        while(i<A.size() && j<B.size())
        {
            vector<int>a=A[i];
            vector<int>b=B[j];
            if(a[1]<b[0]) //Dosent Overlap
                i++;
            else if(b[1]<a[0])//Dosent  Overlap
                j++;
            else
            {
                //If Overlapping
                int start=max(a[0],b[0]);
                int end=min(a[1],b[1]);
                res.push_back({start,end});
            
            
            if(a[1]<b[1]) //Moving to next interval
                i++;
            else if(b[1]<a[1])//Moving to next interval
                j++;
            else
            {
                i++;
                j++;
            }
            }
            
        }
       /* while(i<A.size() && j<B.size())
        {}
            int lo=max(A[i][0],B[j][0]);
            int high=min(A[i][1],B[j][1]);
            if(lo<=high)
                res.push_back({lo,high});
            if(A[i][1]<B[i][1])
                i++;
            else
                j++;
            
        }*/
        return res;
        
    }
};
//Uses the concept of overlapping intervals and combing them.