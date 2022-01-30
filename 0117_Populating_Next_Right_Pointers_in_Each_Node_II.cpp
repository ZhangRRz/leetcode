/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        Node* current_node = root;
        Node* most_left_of_next_level = NULL;
        Node* previous_node = NULL;
        
        // this is base on level order traversal
        
        while(current_node){
            
            while(current_node){
                
                // current_node's left child
                if(current_node -> left){
                    
                    if(most_left_of_next_level == NULL)
                        most_left_of_next_level = current_node -> left;
                    
                    if(previous_node)
                        previous_node -> next = current_node -> left;
                    
                    previous_node = current_node -> left;
                }
                
                // current_node's right child
                if(current_node -> right){
                    
                    if(most_left_of_next_level == NULL)
                        most_left_of_next_level = current_node -> right;
                    
                    if(previous_node)
                        previous_node -> next = current_node -> right;
                    
                    previous_node = current_node -> right;
                    
                }
                // go to the node that right of current node
                current_node = current_node -> next;
                
            }
            
            // go to next(deeper) level
            current_node = most_left_of_next_level;
            previous_node = NULL;
            most_left_of_next_level = NULL;
            
        }    
        return root;
        
    }
    
};
