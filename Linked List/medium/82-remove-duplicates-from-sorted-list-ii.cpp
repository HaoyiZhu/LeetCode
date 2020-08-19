//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中没有重复出现 的数字。

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* d = dummy;
        ListNode* tmp1 = head;

        while(tmp1 && tmp1->next)
        {
            if(tmp1->val != tmp1->next->val)
            {
                d->next = new ListNode(tmp1->val);
                d = d->next;
                tmp1 = tmp1->next;
            }
            else
            {
                while(tmp1->next && tmp1->val == tmp1->next->val)
                {
                    tmp1 = tmp1->next;
                }
                tmp1 = tmp1->next;
            }
        }
        if(tmp1) d->next = new ListNode(tmp1->val);
        return dummy->next;
    }
};