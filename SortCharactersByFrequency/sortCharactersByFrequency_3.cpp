class Solution{
public:
    class comparator{
        public:
        bool operator()(const pair<int, int>&a, const pair<int, int>& b){
            return (a.first > b.first);
        }
    };
    
    string frequencySort(string s){
        vector<pair<int, int>> array(256);
        for(int i = 0; i < 256; ++i){
            array[i] = {0, i};
        }
        for(auto each: s){
            array[each].first++;
        }
        sort(array.begin(), array.end(), comparator());
        for(int i = 0, j = 0; i < 256; ++i){
            if(array[i].first == 0) break;
            while(array[i].first > 0){
                array[i].first--;
                s[j++] = array[i].second;
            }
        }
        return s;
    }
};
