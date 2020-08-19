/*
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。
*/

/*************************************************
- 不断地把child放在curr和next之间。
- 把结构旋转90°，相当于是一个二叉树，next是右孩子，child是左孩子。
- 则可以利用DFS来做。
- 注意操作完要把child删掉。
*************************************************/

// 递归
class Solution {
public:
    Node* DFS(Node* prev, Node* curr){
        if(!curr) return prev;
        prev->next = curr;
        curr->prev = prev;

        Node* right = curr->next;
        Node* tail = DFS(curr,curr->child);
        curr->child = NULL;
        return DFS(tail, right);

    }
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* dummy = new Node(0, NULL, head, NULL);
        DFS(dummy, head);
        dummy->next->prev = NULL;
        return dummy->next;
    }
};

// 迭代（利用栈）
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* dummy = new Node(0, NULL, head, NULL);
        Node* curr = head;
        Node* prev = dummy;
        stack<Node*> s;
        s.push(head);
        while(!s.empty()){
            curr = s.top();
            s.pop();
            curr->prev = prev;
            prev->next = curr;
            if(curr->next) s.push(curr->next);
            if(curr->child){
                s.push(curr->child);
                curr->child = NULL;
            }
            prev = curr;
        }
        dummy->next->prev = NULL;
        return dummy->next;
    }
};