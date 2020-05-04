class Solution {
public:
    //carfully ana;yze XOR truth table you'll understand the solution
    int findComplement(int num) {
        int j=num;
        int count=0;
        while(j!=0){
            j=j/2;
            count++;
        }
        int ans=pow(2,count)-1;
        return num^ans;
        
    }
};