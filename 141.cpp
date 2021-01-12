// 给定一个链表，判断链表中是否有环。

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(true)
        {
            if(fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) return true;
            }
            else return false;
        }
    }
};