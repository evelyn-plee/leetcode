#include<vector>
#include<iostream>
#include<set>

using namespace std;

class Solution{
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values, 
                                vector<pair<string, string>> queries){
        
        vector<double> res(queries.size(), -1);
        set<string> s;

        for(auto a : equations){
            s.insert(a.first); s.insert(a.second);
        }
        for(int i = 0; i < queries.size(); ++i){
            vector<string> query{queries[i].first, queries[i].second};
            if(s.count(query[0]) && s.count(query[1])){
                vector<int> v;
                res[i] = helper(equations, values, query, v);
            }
        }
        return res;
    }

    double helper(vector<pair<string, string>> equations, 
                  vector<double>& values,
                  vector<string> query,
                  vector<int>& v){

        for(int i = 0; i < equations.size(); ++i){
            if(query[0] == equations[i].first && query[1] == equations[i].second) return values[i];
            if(query[1] == equations[i].first && query[0] == equations[i].second) return 1.0/values[i];
            for(int i = 0; i < equations.size(); ++i){
                if(query[0] == equations[i].first && find(v.begin(), v.end(), i) == v.end()){
                    v.push_back(i);
                    double tmp = values[i] * helper(equations, values, {equations[i].second, query[1]}, v);
                    if(tmp > 0) return tmp;
                    else v.pop_back();
                }
                if(query[0] == equations[i].second && find(v.begin(), v.end(), i) == v.end()){
                    v.push_back(i);
                    double tmp = helper(equations, values, {equations[i].first, query[1]}, v) / values[i];
                    if(tmp > 0) return tmp;
                    else v.pop_back();
                }
            }
        }                
        return -1.0;
    }
};
