/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
*/

// 快慢指针 O(nlogn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

// 中序遍历优化 O(n)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode* tmp = head;
        while(tmp){
            length++;
            tmp = tmp->next;
        }
        return buildtree(head, 0, length-1);
    }
private:
    TreeNode* buildtree(ListNode*& head, int left, int right){  // 注意是对指针的引用！！！！！！！！！！！！！
        if(left > right) return NULL;
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildtree(head, left, mid-1);
        root->val = head->val;
        head = head->next;
        root->right = buildtree(head, mid+1, right);
        return root;
    }
};
