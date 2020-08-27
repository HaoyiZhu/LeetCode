/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶：
如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
*/

// 栈
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //if(!l1->val) return l2;
        //if(!l2->val) return l1;

        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* res = nullptr;
        while(!s1.empty() or !s2.empty() or carry){
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            int sum = a + b + carry;
            ListNode* cur = new ListNode(sum % 10);
            carry = sum / 10;
            cur->next = res;
            res = cur;
        }
        return res;
    }
};