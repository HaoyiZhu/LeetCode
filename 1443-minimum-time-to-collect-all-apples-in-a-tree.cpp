/*
给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。
你从 节点 0 出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。

无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi 。
除此以外，还有一个布尔数组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i 没有苹果。
*/
class Solution {
private:
    unordered_map<int, vector<int>> m;
    bool util(int idx, vector<bool>& hasApple) {
        bool under_has_apple = hasApple[idx];
        for(auto& i : m[idx]) {
            under_has_apple = util(i, hasApple) || under_has_apple; // util(i, hasApple)一定要在前，否则可能会不执行递归，会忽略子树上的苹果
        }

        if(!under_has_apple) {
            m.erase(idx);
        }
        return under_has_apple;
    }
    // 把父节点删掉，保证map中每个key只有他的子节点
    void clean_map(const int root) {
        for(auto& i: m[root]) {
            for (auto it = m[i].begin(); it != m[i].end(); ++it)
                {
                    if (*it == root)
                    {
                        m[i].erase(it);
                        break;
                    }
                }
            clean_map(i);
        }
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto& node_pair : edges) {
            m[node_pair[0]].push_back(node_pair[1]);
            m[node_pair[1]].push_back(node_pair[0]);
        }

        clean_map(0);
        util(0, hasApple);

        return m.empty() ? 0 : 2 * (m.size() - 1);
    }
};