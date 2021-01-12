/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：
- get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
- addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
- addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
- addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
- deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/

// 双链表

class MyLinkedList {
private:
    struct MyLinkedNode{
        int val;
        MyLinkedNode *prev;
        MyLinkedNode *next;
        MyLinkedNode(int x){val = x; prev = nullptr; next = nullptr;}
    };
    int size = 0;
    MyLinkedNode *head;
    MyLinkedNode *tail;
    /*
    void debug()
    {
        MyLinkedNode *tmp = head;
        while(tmp) {cout << tmp->val; tmp = tmp->next;}
        cout << endl;
        delete tmp;
    }
    */
public:
    /** Initialize your data structure here. */
    MyLinkedList():size(0),head(nullptr),tail(nullptr){}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        MyLinkedNode *tmp = head;
        for(int i = 0; tmp->next && i < index; i++)
            tmp = tmp->next;
        if(tmp) return tmp->val;
        else return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(!head) {head = new MyLinkedNode(val); tail = head;}
        else
        {
            head->prev = new MyLinkedNode(val);
            head->prev->next = head;
            head = head->prev;
        }
        size++;
        //debug();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(!tail) {head = new MyLinkedNode(val); tail = head;}
        else
        {
            tail->next = new MyLinkedNode(val);
            tail->next->prev = tail;
            tail = tail->next;
        }
        size++;
        //debug();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == size) {addAtTail(val); return;}
        else if(index == 0) {addAtHead(val); return;}
        else{
            MyLinkedNode *tmp = head;
            MyLinkedNode *target = new MyLinkedNode(val);
            for(int i = 0; i < index - 1; i++)
                tmp = tmp->next;
            target->next = tmp->next;
            target->prev = tmp;
            tmp->next->prev = target;
            tmp->next = target;
        }
        size++;
        //debug();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        MyLinkedNode *tmp = head;
        if(index == 0){
            tmp = head;
            head = head->next;
        }
        else if(index == size - 1){
            tmp = tail;
            tail = tail->prev;
        }
        else{
            for(int i = 0; i < index; i++)
                tmp = tmp->next;
            tmp->prev->next = tmp->next;
            if(tmp->next) tmp->next->prev = tmp->prev;
        }
        delete tmp;
        size--;
        //debug();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */