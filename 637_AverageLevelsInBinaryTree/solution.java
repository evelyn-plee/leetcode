class Solution{
    public List<Double> averageOfLevel(TreeNode node){
    
        List<Integer> count = new ArrayList<>();
        List<Double> res = new ArrayList<>();
        average(node, 0, count, res);
        for(int i = 0; i < res.size(); i++){
            res.set(i, res.get(i) / count.get(i));
        }
        return res;
    }
    
    private void average(TreeNode node, int i, List<Double> sum, List<Integer> count){
        if(node == null) return;
    
        if(i < sum.size()){
            sum.set(i, sum.get(i) + node.val);
            count.set(i, count.get(i) + 1);
        }else{
            sum.add(node.val);
            count.add(1);
        }
        
        average(node.left, i + 1, sum, count);
        average(node.right, i + 1, sum, count);
    }
}
