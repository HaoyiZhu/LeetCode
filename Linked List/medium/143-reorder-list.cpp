/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

 //递归
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        int length = 0;
        ListNode* tmp = head;
        while(tmp){
            length++;
            tmp = tmp->next;
        }
        _reorderList(head, length);
    }
private:
    ListNode* _reorderList(ListNode* head, int length){
        if(length == 1){
            ListNode* out = head->next;
            head->next = NULL;
            return out;
        }
        if(length == 2){
            ListNode* out = head->next->next;
            head->next->next = NULL;
            return out;
        }
        ListNode* tail = _reorderList(head->next, length-2);
        ListNode* out = tail->next;
        tail->next = head->next;
        head->next = tail;
        return out;
    }
};


// 1）分成前后两部分
// 2）把后面倒置
// 3）交替插入
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* new_head = slow->next;
        slow->next = NULL;
        new_head = reverse(new_head);

        while(new_head){
            fast = new_head->next;
            new_head->next = head->next;
            head->next = new_head;
            new_head = fast;
            head = head->next->next;
        }
    }
private:
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode* tail = head;
        head = head->next;
        tail->next = NULL;
        while(head){
            ListNode* tmp = head;
            head = head->next;
            tmp->next = tail;
            tail = tmp;
        }
        return tail;
    }
};