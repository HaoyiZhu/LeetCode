/*
对链表进行插入排序。
*/

// nothing important
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head->next;
        ListNode* tail = head;
        while(cur){
            if(cur->val < tail->val){
                ListNode* tmp = dummy;
                while(tmp->next->val < cur->val)
                    tmp = tmp->next;
                tail->next = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = tail->next;
            }
            else{
                tail = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};