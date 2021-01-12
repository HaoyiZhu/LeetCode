# 给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个从 0 到 25 的值，分别代表字母 'a' 到 'z'：值 0 代表 'a'，值 1 代表 'b'，依此类推。
# 找出按字典序最小的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。

# 暴力法
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        self.res = '{'

        def dfs(node: TreeNode, string: str):
            if node:
                string += chr(node.val + ord('a'))
                if not node.left and not node.right:
                    self.res = min(self.res, string[::-1])
                dfs(node.left, string)
                dfs(node.right, string)

        dfs(root, '')
        return self.res