/**
* Time complexity: O(n)
*/

class Codec{
public:
    // Encodes a tree to a single string
    string serialize(TreeNode* root){
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    
    // Decodes your encoded data to a tree
    TreeNode* deserialize(string data){
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream& out){
        if(!root){
            out << "# "; 
            return;
        }
        out << root->val << " ";
        serialize(root->left);
        serialize(root->right);
    }
    
    TreeNode* deserialize(istringstream in){
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(in));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
