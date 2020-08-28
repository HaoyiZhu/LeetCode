/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* res1 = new ListNode(0);
        ListNode* res2 = new ListNode(0);
        ListNode* tmp1 = res1;
        ListNode* tmp2 = res2;
        while(head){
            if(head->val < x){
                tmp1->next = new ListNode(head->val);
                tmp1 = tmp1->next;
            }
            else{
                tmp2->next = new ListNode(head->val);
                tmp2 = tmp2->next;
            }
            head = head->next;
        }
        tmp1->next = res2->next;
        return res1->next;
    }
};