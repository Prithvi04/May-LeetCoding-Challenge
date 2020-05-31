class Solution {
public:
    //Popular DP question
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int dp[m+1][n+1];
        //Base cases
        for(int i=0;i<=m;i++)//if(m==0) return n; 
            dp[i][0]=i;
        for(int j=0;j<=n;j++)// if(n==0) return m;
            dp[0][j]=j;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1]) //When the characters are same
                    dp[i][j]=dp[i-1][j-1];//Same value without them
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                //Add 1+ minimum of Insert, Delete and Replace Operations
            }
        }
        return dp[m][n];
    }
};