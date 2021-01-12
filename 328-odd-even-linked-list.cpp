/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd_tail = head;
        ListNode* even_tail = head->next;
        ListNode* even_head = even_tail;

        while(even_tail && even_tail->next){
            odd_tail->next = even_tail->next;
            odd_tail = odd_tail->next;
            even_tail->next = odd_tail->next;
            even_tail = even_tail->next;
        }
        odd_tail->next = even_head;
        return head;
    }
};