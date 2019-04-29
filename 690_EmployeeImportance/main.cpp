/*
// Employee info
class Employee{
public:
    // It's the unique ID of each code.
    // unique id of this employee
    int id;
    
    // the importance value of this employee
    int importance;
    
    // the id of direct subordinates
    vector<int> subordindates;
}

class BFS_Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importanceSum = 0;
        
        unordered_map<int, Employee*> pool;
        for(auto e : employees){
            pool[e->id] = e;
        }
        
        queue<Employee*> q;
        q.push(pool[id]);
        while(!q.empty()){
            Employee* emp = q.front(); q.pop();
            importanceSum += emp->importance;
            for(int e : emp->subordinates){
                q.push(pool[e]);
            }
        }
        return importanceSum;
    }
};

class DFS_Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> pool;
        for(auto e : employees){
            pool[e->id] = e;
        }
        return getSum(pool, id);
    }
private:
    int getSum(unordered_map<int, Employee*>& pool, int id){
        int sum = pool[id]->importance;
        for(auto e : pool[id]->subordinates){
            sum += getSum(pool, e);
        }
        return sum;
    }
