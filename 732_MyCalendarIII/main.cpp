// Time Complexity: O(n^2), for each query in n, we have to loop through the entire map
// Space Complexity: O(n)
class MyCalendarThree{
private:
    map<int, int> delta_;
public:
    MyCalendarThree(){}
    
    int book(int start, int end){
        ++delta_[start];
        --delta_[end];
        int ans = 0, cnt = 0;
        for(auto &kv : delta_){
            ans = max(ans, cnt += kv.second);
        }
        return ans;
    }
};


// Use Segment Tree

class MyCalendarThree{
public:
    MyCalendarThree(): max_count_(0){
        root_.reset(new Node(0, 100000000, 0));
    }
    
    int book(int start, int end){
        Add(start, end, root_.get());
        return max_count_;
    }

private:
    struct Node{
        Node(int l, int r, int count): l(l), m(-1), r(r), count(count){}
        int l; int m; int r; int count;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };
    
    void Add(int start, int end, Node* root){
        if(root->m != -1){
            if(end <= root->m) Add(start, end, root->left.get()); // Traverse the left tree
            else if(start >= root->m) Add(start, end, root->right.get()); // Traverse the right tree
            else{
                // Split the input range into left tree and right tree
                Add(start, root->m, root->left.get());
                Add(root->m, end, root->right.get());
            }
            return;
        }
    
        // Reaching the leaves part
        // exact match
        if(start == root->l && end == root->r) max_count_ = max(max_count_, ++root->count);
        else if(start == root->l){
            // match the left node of root
            root->m = end;
            root->left.reset(new Node(root->l, root->m, root->count + 1));
            root->right.reset(new Node(root->m, root->r, root->count));
            max_count_ = max(max_count_, root->count + 1);
        }else if(start == root->r){
            // match the right node of root
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count + 1));
            max_count_ = max(max_count_, root->count + 1); 
        }else{
            // No match, need to add 2 layers
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count));
            Add(start, end, root->right.get());
        }
    }

    std::unique_ptr<Node> root_;
    int max_count_;
};
