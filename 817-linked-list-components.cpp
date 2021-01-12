/*
给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。
同时给定列表 G，该列表是上述链表中整型值的一个子集。
返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
*/

// unordered_set
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        unordered_set<int> s;
        for(int i : G) s.insert(i);        
        ListNode* cur = head;

        while(cur){
            if(s.find(cur->val) != s.end() &&
                (!cur->next || s.find(cur->next->val) == s.end()))
                res++;
            cur = cur->next;
        }
        return res;
    }
};