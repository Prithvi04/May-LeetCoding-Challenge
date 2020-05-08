class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //Use colinearity between 2-points, cross multilple slopes betweeen first 2-points and rest of points
        //Don't use division anywhere ,as you'll division by zero exception
        int s=coordinates.size();
        if(s<2)
            return false;
        if(s==2)
            return true;
        int ydiff=(coordinates[1][1]-coordinates[0][1]);
        int xdiff=(coordinates[1][0]-coordinates[0][0]);
        
        for(int i=3;i<s;i++)
        {
            //(coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0]);
            
            if((coordinates[i][1]-coordinates[i-1][1])*xdiff != (coordinates[i][0]-coordinates[i-1][0])*ydiff)
                return false;
        }
        return true;
        
    }
};