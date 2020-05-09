class Solution {
public:
    /*
    1=1
    1+3=4
    1+3+5=9
    1+3+5+7=16 and so on....

    keep incrementing i by 2 and decrementing num by i, check if it becomes zero(it's perfect square), if it becomes negative its not a perfect square.


    */
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0)
        {
            num-=i;
            i+=2;
            if(!num)
                return true;
        }
        return false;
        
    }
};