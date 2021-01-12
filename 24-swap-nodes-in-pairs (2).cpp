// 重复了。。。又做了一遍 =_=

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = dummy;

        while(cur && cur->next){
            prev->next = cur->next;
            //ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            prev->next->next = cur;
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};