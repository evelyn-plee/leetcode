class ZigzagIterator{
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2){
        p = 0;
        b[0] = v1.begin(), b[1] = v2.begin();
        e[0] = v1.end(), e[1] = v2.end();
    }
    
    int next(){
        int val;
        if(b[0] == e[0]) val = *b[1]++;
        else if(b[1] == e[1]) val = *b[0]++;
        else{
            val = *b[p]++;
            p = (p + 1) % 2;
        }
        return val;
    }
    
    bool hasNext(){
        return b[0] != e[0] || b[1] != e[1];
    }
    
private:
    int p;
    vector<int>::iterator b[2], e[2];
};
