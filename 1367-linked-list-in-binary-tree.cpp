/*
给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False 。
一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
*/

// 递归 + 枚举

class Solution {
private:
    bool match(TreeNode *root, ListNode *head){
        if(!head) return true;
        if(!root || root->val != head->val) return false;
        return match(root->left, head->next) || match(root->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        if(match(root, head)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};