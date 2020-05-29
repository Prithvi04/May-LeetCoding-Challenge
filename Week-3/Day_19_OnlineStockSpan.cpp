class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
        stack<pair<int,int>>s;
        
    }
    
    int next(int price) {
        int span=1;
        while(s.empty()==false && s.top().first<=price)
        {
            span+=s.top().second;
            s.pop();
            
            
        }
        s.push(make_pair(price,span));
        return span;
            
        
        
    }
};
//Functional problem: Impliment appropriate Data structure for the Online Stock Span
//I Implimented Stack data structure to solve the problem.

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */