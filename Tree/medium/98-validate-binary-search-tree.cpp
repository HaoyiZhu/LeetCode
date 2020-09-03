/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：
- 节点的左子树只包含小于当前节点的数。
- 节点的右子树只包含大于当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isValidBST(TreeNode* root, long long min, long long max){
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return _isValidBST(root->left, min, root->val) && _isValidBST(root->right, root->val, max);
    }
};