
struct Mynode {
    int val;
    Mynode *next;
    Mynode() : val(0), next(nullptr) {}
    Mynode(int x) : val(x), next(nullptr) {}
    Mynode(int x, Mynode *next) : val(x), next(next) {}
};


class MyLinkedList {
public:
    MyLinkedList() {
        int length = 0;
        Mynode *head = nullptr;
        Mynode *tail = nullptr;
    }
    
    int get(int index) {
        if(length <= index)
            return -1;
        Mynode *cur = head;
        while(index--)
            cur = cur -> next;
        
        return cur -> val;
    }
    
    void addAtHead(int val) {
        head = new Mynode(val,head);
        if(!tail)
            tail = head;
        length++;
    }
    
    void addAtTail(int val) {
        if(!head){
            head = new Mynode(val,head);
            tail = head;
        }else{
            tail -> next = new Mynode(val);
            tail = tail -> next;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(length < index)
            return;
        else if(length == index){
            addAtTail(val);
        }
        else if(0 == index){
            addAtHead(val);
        }
        else{

            Mynode *cur = head;
            index--;
            while(index--)
                cur = cur -> next;

            cur -> next = new Mynode(val,cur -> next);
            length++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(length <= index)
            return;
        else if(0 == index){ //delete head;
            Mynode *cur = head;
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }else{
                head = head -> next;
                delete(cur);
            }
        }
        else{
            Mynode *cur = head;
            index--;
            while(index--)
                cur = cur -> next;
            
            if(cur -> next == tail){ //delete tail
                tail = cur;
            }
            
            Mynode *tmp = cur -> next;
            cur -> next = tmp -> next;
            delete(tmp);
            
        
        }
            
        length--;

    }
    
private:
    int length = 0;
    Mynode *head = nullptr;
    Mynode *tail = nullptr;
    
};
