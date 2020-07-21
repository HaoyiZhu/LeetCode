// 编写一个程序，找到两个单链表相交的起始节点。

// notice that len(A+B) == len(B+A)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        while(a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};