class Solution {
public:
    //Use Depth First search to change colour of all the adjacents from the position (sr,sc) from the original image.   
    void DFS(vector<vector<int>>& image, int i, int j,int m,int n,vector<vector<bool>> vis, int newColor,int x)
    {
        vis[i][j]=true;
        image[i][j]=newColor;
        if(i+1>=0 && i+1<m && image[i+1][j]==x && vis[i+1][j]==false)
            DFS(image,i+1,j,m,n,vis,newColor,x);
        if(i-1>=0 && i-1<m && image[i-1][j]==x && vis[i-1][j]==false)
            DFS(image,i-1,j,m,n,vis,newColor,x);
        if(j+1>=0 && j+1<n && image[i][j+1]==x && vis[i][j+1]==false)
            DFS(image,i,j+1,m,n,vis,newColor,x);
        if(j-1>=0 && j-1<n && image[i][j-1]==x && vis[i][j-1]==false)
            DFS(image,i,j-1,m,n,vis,newColor,x);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        if(m==0 || n==0)
            return image;
        int x=image[sr][sc];
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        DFS(image,sr,sc,m,n,vis,newColor,x);
        return image;
        
    }
};