/*
给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。
由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。
*/

// DFS遍历求和，找到一个子树的和最接近总和的一半
class Solution {
private:
    int sum = 0;
    int target = 0;
    void dfs_sum(TreeNode* root){
        if(!root) return;
        sum += root->val;
        dfs_sum(root->left);
        dfs_sum(root->right);
    }
    int dfs_find(TreeNode* root){
        if(!root) return 0;
        int cur = dfs_find(root->left) + dfs_find(root->right) + root->val;
        if(abs(cur*2 - sum) < abs(target*2 - sum)) target = cur;
        return cur;
    }
public:
    int maxProduct(TreeNode* root) {
        dfs_sum(root);
        dfs_find(root);
        return (long long) target*(sum-target) % 1000000007;
    }
};