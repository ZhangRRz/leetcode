/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> pre;
    vector<int> preorder(Node* root) {
        
        Preorder_Traversal(root);
        
        return pre;
    }
    
    void Preorder_Traversal(Node* cur){
        
        if(!cur)
            return;
        pre.push_back(cur -> val);
        
        for(int i = 0;i < (cur -> children).size();i++){
            Preorder_Traversal((cur -> children)[i]);
        }
    }
    
    
};
