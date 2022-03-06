/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<int> in_order_vec;
    int cur_vec_index = 0;
    
public:
    void in_order_traversal(TreeNode* cur_node){
        if(!cur_node)
            return;
        in_order_traversal(cur_node -> left);
        in_order_vec.push_back(cur_node -> val);
        in_order_traversal(cur_node -> right);
        
        return;
    }
    
    
    BSTIterator(TreeNode* root) {
        in_order_traversal(root);
    }
    
    
    int next() {
        return in_order_vec[cur_vec_index++];
    }
    
    bool hasNext() {
          return cur_vec_index != in_order_vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
