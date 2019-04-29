/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    Map<Integer, Employee> pool;
    
    public int getImportance(List<Employee> employees, int id) {
        pool = new HashMap();
        for(Employee e : employees) pool.put(e.id, e);
        return getSum(id);
    }
    
    private int getSum(int id){
        Employee employee = pool.get(id);
        int ans = employee.importance;
        for(Integer subId : employee.subordinates) ans += getSum(subId);
        return ans;
    }
}
