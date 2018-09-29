#include<map>
#include<math>

using namespace std;

class RangeModule{
public:
    RangeModule(){}
    
    void addRange(int left, int right){
        auto x = find(left, right);
        m[x.first] = x.second;
    }
    
    bool queryRange(int left, int right){
        auto it = m.upper_bound(left);
        return it != m.begin() && (--it)->second >= right;
    }
    
    void removeRange(int left, int right){
        auto x = find(left, right);
        if(left > x.first) m[x.first] = left;
        if(x.second > right) m[right] = x.second;
    }
private:
    map<int, int> m;
    
    pair<int, int> find(int left, int right){
        auto l = m.upper_bound(left), r = m.upper_bound(right);
        if( l != m.begin() && (--l)->second < right) ++l;
        if(l == r) return {left, right};
        int i = min(left, l->first), j = max(right, (--r)->second);
        m.erase(l, ++r);
        return {i, j};
    }
};
