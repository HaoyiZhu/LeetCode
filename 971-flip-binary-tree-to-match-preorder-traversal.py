'''
给定一个有 N 个节点的二叉树，每个节点都有一个不同于其他节点且处于 {1, ..., N} 中的值。
通过交换节点的左子节点和右子节点，可以翻转该二叉树中的节点。
考虑从根节点开始的先序遍历报告的 N 值序列。将这一 N 值序列称为树的行程。
（回想一下，节点的先序遍历意味着我们报告当前节点的值，然后先序遍历左子节点，再先序遍历右子节点。）
我们的目标是翻转最少的树中节点，以便树的行程与给定的行程 voyage 相匹配。 

如果可以，则返回翻转的所有节点的值的列表。你可以按任何顺序返回答案。
如果不能，则返回列表 [-1]。
'''

# 深度优先搜索
class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        self.res = []
        self.idx = 0

        def dfs(root: TreeNode):
            if not root:
                return
            if root.val != voyage[self.idx]:
                self.res = [-1]
                return

            self.idx += 1
            if self.idx < len(voyage) and root.left and root.left.val != voyage[self.idx]:
                self.res.append(root.val)
                dfs(root.right)
                dfs(root.left)
            else:
                dfs(root.left)
                dfs(root.right)
        
        dfs(root)
        if self.res and self.res[0] == -1:
            return [-1]
        return self.res