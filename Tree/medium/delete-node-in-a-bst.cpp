/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：
	- 首先找到需要删除的节点；
	- 如果找到了，删除它。
*/
/* 找：
   - 如果当前节点值小于key，则在右子树上
   - 如果当前节点值大于key，则在左子树上
   - 如果当前节点值等于key，执行删
   删：
   - 如果是叶子节点，直接删
   - 如果只有左子树或者只有右子树，直接接上
   - 如果都有，则找到右子树上最小的替代，然后把右子树上最小的删掉
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else{
            if(!root->left && !root->right) return nullptr;
            else if(root->right && !root->left) return root->right;
            else if(root->left && !root->right) return root->left;
            else {
                TreeNode* successor = root->right;
                TreeNode* precessor = root;
                while(successor->left) {
                    precessor = successor;
                    successor = successor->left;
                }
                root->val = successor->val;
                if(successor == precessor->right) precessor->right = deleteNode(successor, successor->val);
                else precessor->left = deleteNode(successor, successor->val);
            }
        }
        return root;
    }
};