/*
给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。
*/

/*****************************************************
1. 快慢指针判断是否有环
2.若有环，设相遇在c点。设表头为a，环头为b。则len(a->b->c->b->c) = 2*len(a->b->C)
  即len(a->b->c) = len(c->b->c), 则len(a->b) = len(c->b)
3.那么只需把fast置于head，让他保持与slow相同速度，再次相遇时即为b点，也就是环头。
******************************************************/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow != fast) return NULL;
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};