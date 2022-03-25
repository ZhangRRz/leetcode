/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
int a = 10;
stringstream ss;
ss << a;
string str = ss.str();
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> bfs;
        
        bfs.push(root);
        string ans = "";
        bool still_have_node = true;
        
        while(still_have_node){
            int n = bfs.size();
            still_have_node = false;
            
            while(n--){
                if(bfs.front() == nullptr){
                    ans += "null,";
                }
                else{
                    
                    stringstream ss;
                    ss << bfs.front()->val;
                    ans += ss.str();
                    ans += ",";    
                    
                    if(bfs.front()->left || bfs.front()->right){
                        still_have_node = true;
                    }
                    bfs.push(bfs.front()->left);
                    bfs.push(bfs.front()->right);
                }
                bfs.pop();
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        
        queue<TreeNode*> node_ptr;
        string tmp = "";
        
        // ==========================================
        // first create root;
        // ==========================================
        int i = 0;
        for(;i < data.size();i++){
            if(data[i] != ','){
                tmp += data[i];
            }else{
                break;
            }
        }
        TreeNode* root;
        if(tmp[0] == 'n'){
            return nullptr;
        }else{
            root = new TreeNode(stoi(tmp));
            node_ptr.push(root);
        }
        
        // ==========================================
        // then handle all the subtree
        // lchild indicate now should add leftchild(1) or rightchild(0)
        // ==========================================
        tmp = "";
        // move on to left child of root;
        i++;
        int lchild = 1;
        for(;i < data.size();i++){
            
            
            if(data[i] != ','){
                tmp += data[i];
            }
            else{  // if see a ',' means "tmp" already collect the data of a node
                
                if(node_ptr.front() == nullptr){ // if current node is nullptr
                    node_ptr.pop();
                }
                else if(tmp[0] =='n'){ //tmp is "null"
                    if(lchild)
                        lchild = 0;
                    else{
                        lchild = 1;
                        node_ptr.pop();
                    }
                }
                else{
                    if(lchild){
                        node_ptr.front() -> left = new TreeNode(stoi(tmp));
                        node_ptr.push(node_ptr.front() -> left);
                        lchild = 0;
                    }else{
                        node_ptr.front() -> right = new TreeNode(stoi(tmp));
                        node_ptr.push(node_ptr.front() -> right);
                        lchild = 1;
                        // after add right child ,pop the queue
                        // this means pop the node that two child are processed
                        node_ptr.pop();
                    }
                }
                // remember clear the tmp
                tmp = "";
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
