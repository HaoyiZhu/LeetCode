/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<ListNode*> s;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int i = 0;
        for(i = 0; i < m-1; i++){
            curr = curr->next;
        }
        ListNode* start = curr->next;
        for(i = m; i <= n; i++){
            s.push(start);
            start = start->next;
        }

        ListNode* tail = start;
        while(!s.empty()){
            curr->next = s.top();
            s.pop();
            curr = curr->next;
        }
        curr->next = tail;
        return dummy->next;
    }
};