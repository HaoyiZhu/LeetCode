// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 注意要有一个哨兵节点，还要一个指针记录每次变换的两个节点的前一节点。

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *tmp = head->next;
        ListNode *first = head;
        ListNode *prev = new ListNode(-1);
        prev->next = head;
        ListNode *result = prev;
        while(first && first->next)
        {
            prev->next = tmp;
            first->next = tmp->next;
            tmp->next = first;
            prev = first;
            first = first->next;
            if(first && first->next) tmp = first->next;
        }
        return result->next;
    }
};