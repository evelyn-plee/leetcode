class myCompare
{
public:
    bool operator() (pair<int, char> p1, pair<int, char> p2)
    {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        string ans;
        if(!n) return ans;
        priority_queue<pair<int, char> , vector<pair<int, char>>, myCompare> pq;
        
        int a[256];
        memset(a, 0, sizeof(a));
        
        for(int i = 0; i<n; i++) a[s[i]]++;
        for(int i = 0; i<256; i++)
        {
            if(a[i]) pq.push(make_pair(a[i], i));
        }
        while(!pq.empty())
        {
            auto pair = pq.top();
            for(int i = 0; i<pair.first; i++) ans += char(pair.second);
            pq.pop();
        }
        
        return ans;    
    }
};
