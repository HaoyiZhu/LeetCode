/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 `[val, random_index]` 表示：
- `val`：一个表示 `Node.val` 的整数。
- `random_index`：随机指针指向的节点索引（范围从 `0`到 `n-1`）；如果不指向任何节点，则为  `null` 。
*/

//An amazing solution!!!!!!

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* tmp = head;
        while(tmp){
            Node* new_node = new Node(tmp->val);
            new_node->next = tmp->next;
            tmp->next = new_node;
            tmp = tmp->next->next;
        }

        tmp = head;
        while(tmp){
            tmp->next->random = tmp->random ? tmp->random->next : NULL;
            tmp = tmp->next->next;
        }

        Node* origin_list = head;
        Node* new_list = head->next;
        Node* res = head->next;
        while(origin_list){
            origin_list->next = origin_list->next->next;
            new_list->next = new_list->next ? new_list->next->next : NULL;
            origin_list = origin_list->next;
            new_list = new_list->next;
        }
        return res;

    }
};