class Solution {
public:
    string removeKdigits(string num, int k) {
        //The idea is to flatten the peaks while traversing from the left side
        //The idea is based on the understanding that lsb has less weightage compared to msb in determining a value
        
        
        int n=num.size();
        stack<char>s;
        for(char c:num)
        {
            while(!s.empty() && k>0 && int(s.top())>int(c))
            {
                s.pop();
                k-=1;
            }
            if(!s.empty() || c!='0')
                s.push(c);
        }
        
        while(!s.empty() && k>0)
        {
            s.pop();
            k--;
        }
        if(s.empty())
            return "0";
        
        while(!s.empty())
        {
            num[n-1]=s.top();
            s.pop();
            n--;
        }
        return num.substr(n);
    }
};