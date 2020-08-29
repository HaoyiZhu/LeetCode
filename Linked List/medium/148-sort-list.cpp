// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

// 二分 + 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* new_head = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(new_head);

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(left && right){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
                cur = cur->next;
            }
            else{
                cur->next = right;
                right = right->next;
                cur = cur->next;
            }
        }
        cur->next = left ? left : right;
        return res->next;
    }
};