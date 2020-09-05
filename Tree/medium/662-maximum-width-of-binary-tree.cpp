/*
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。
这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
*/

 // 层序遍历 广度优先搜索
 // 记录位置和层数信息
class Solution {
private:
    struct mynode{
        TreeNode* node;
        unsigned long long position;    // 一定要用这个类型，否则会integer overflow!!!!!!
        int depth;
        mynode(TreeNode* n, unsigned long long p, int d): node(n), position(p), depth(d){};
    };
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<mynode> q;
        mynode node(root, 0, 0);
        q.push(node);
        int level = 0;
        int res = 0;
        unsigned long long left_position = 0;
        while(!q.empty()){
            mynode cur_node = q.front();
            q.pop();
            if(cur_node.node){
                q.push(mynode(cur_node.node->left, cur_node.position * 2, cur_node.depth + 1));
                q.push(mynode(cur_node.node->right, cur_node.position * 2 + 1, cur_node.depth + 1));
                if(level != cur_node.depth){
                    left_position = cur_node.position;
                    level++;
                }
                res = res > cur_node.position-left_position+1 ? res : cur_node.position-left_position+1;
            }
        }
        return res;
    }
};