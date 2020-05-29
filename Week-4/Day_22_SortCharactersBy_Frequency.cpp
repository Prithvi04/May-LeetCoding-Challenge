class Solution {
public:
    string frequencySort(string s) {
         vector<int>mp(128,0);
        for(auto ch:s)
        {
            mp[ch-' ']++;
        }
        sort(s.begin(),s.end(),[&](const char a,const char b)
             {
                 if(mp[a-' ']!=mp[b-' '])
                 {
                     return mp[a-' ']>mp[b-' '];
                 }
                 else{
                     return a>b;
                 }
             });
        return s;
    }
};
//Using Lambda function to sort character by frequency and descending order.