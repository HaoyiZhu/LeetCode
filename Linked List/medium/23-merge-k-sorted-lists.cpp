/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

 // 无脑
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for(int i = 0; i < lists.size(); i++)
            res = mergeTwoLists(res, lists[i]);
        return res;
    }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if(!a || !b) return a ? a : b;
        ListNode* head = new ListNode();
        ListNode* tail;
        tail = head;
        
        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head->next;
    }
};

// 分治
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if(!a || !b) return a ? a : b;
        ListNode* head = new ListNode();
        ListNode* tail;
        tail = head;
        
        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
};

// 优先级队列
class Solution {
public:
    struct Status{
        ListNode* ptr;
        bool operator < (const Status tmp) const{
            return ptr->val > tmp.ptr->val;
        }
    };
    priority_queue<Status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node : lists){
            if(node) q.push({node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next});
        }
        return head.next;
    }

};