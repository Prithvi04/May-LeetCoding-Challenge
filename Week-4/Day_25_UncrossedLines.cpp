class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1]) // Both elements same in that index
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]); // Maximum value excluding that index both array's
            }
        }
        return dp[m][n];
        
    }
};
//Classical Case of repeating subsequence which can be optimized using DP
