// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

// 感觉可以归到simple里
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = 0;
        ListNode *pos = head;
        ListNode *tail = pos;
        while(pos)
        {
            len++;
            tail = pos;
            pos = pos->next;
        }
        tail->next = head;
        tail = pos = head;
        for(int i = 0; i < len - k % len; i++)
        {
            tail = pos;
            pos = pos->next;
        }
        tail->next = NULL;
        return pos;
    }
};