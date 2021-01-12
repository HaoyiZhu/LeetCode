/*
给定二叉树，按垂序遍历返回其结点值。

对位于 (X, Y) 的每个结点而言，其左右子结点分别位于 (X-1, Y-1) 和 (X+1, Y-1)。
把一条垂线从 X = -infinity 移动到 X = +infinity ，每当该垂线与结点接触时，我们按从上到下的顺序报告结点的值（ Y 坐标递减）。
如果两个结点位置相同，则首先报告的结点值较小。
按 X 坐标顺序返回非空报告的列表。每个报告都有一个结点值列表。
*/

// 用map记录每个节点的坐标信息
// 用sort排序
class Solution {
private:
    map<int, vector<pair<int, int>>> m;
    void dfs(TreeNode* root, int x, int y){
        if(!root) return;
        m[x].push_back({y, root->val});
        dfs(root->left, x-1, y+1);
        dfs(root->right, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> res;
        for(auto& p : m){   // 对于m中的每一个键值对
            sort(p.second.begin(), p.second.end());
            vector<int> v;
            for(auto t : p.second){    // 对于每个键值对中的pair值
                v.push_back(t.second);
            }
            res.push_back(v);
        }
        return res;
    }
};