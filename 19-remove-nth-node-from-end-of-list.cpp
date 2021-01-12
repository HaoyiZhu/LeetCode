// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 快慢双指针！！！！！！

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *fast = result;
        ListNode *slow = result;
        for(int i=0; i < n+1; i++) // n + 1!!!
            fast = fast->next;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return result->next;
    }
};