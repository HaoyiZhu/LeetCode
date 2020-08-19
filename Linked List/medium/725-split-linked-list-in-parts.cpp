/*
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
*/


// nothing unusual


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        vector<ListNode*> res(k, NULL);
        ListNode* tmp = root;
        while(tmp){
            length++;
            tmp = tmp->next;
        }
        int size = length / k;
        int rest = 0;
        if(size) rest = length % k;
        tmp = root;
        for(int i=0; i<k; i++){
            res[i] = tmp;
            for(int j=0; j<size-1; j++){
                tmp = tmp->next;
            }
            if(rest>0){
                rest--;
                tmp = tmp->next;
            }
            if(tmp){
                ListNode* prev = tmp;
                tmp = tmp->next;
                prev->next = NULL;
            }
        }
        return res;
    }
};