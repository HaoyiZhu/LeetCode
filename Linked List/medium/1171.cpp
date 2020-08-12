/*
给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
删除完毕后，请你返回最终结果链表的头节点。
你可以返回任何满足题目要求的答案。
*/

// 循环两次map！！！

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        map<int,ListNode*> map;
        int sum = 0;

        for(ListNode* d = dummy; d; d = d->next)
        {
            sum += d->val;
            map[sum] = d;
        }

        sum = 0;
        for(ListNode* d = dummy; d; d = d->next)
        {
            sum += d->val;
            d->next = map[sum]->next;
        }

        return dummy->next;
    }
};