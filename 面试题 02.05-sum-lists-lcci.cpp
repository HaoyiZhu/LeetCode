/*
给定两个用链表表示的整数，每个节点包含一个数位。
这些数位是反向存放的，也就是个位排在链表首部。
编写函数对这两个整数求和，并用链表形式返回结果。
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        ListNode* tmp = dummy;
        while(l1 || l2)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            tmp->next = new ListNode(sum % 10);
            tmp = tmp->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            carry = sum / 10;
        }
        if(carry) tmp->next = new ListNode(carry);
        return dummy->next;
    }
};