/*
给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，
那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。
*/

// 利用*单调栈*

// original solution
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> tmp;   // <num, val>
        int num = 0;

        while(head){
            res.push_back(0);
            while(!tmp.empty() && head->val > tmp.top().second){
                res[tmp.top().first] = head->val;
                tmp.pop();
            }
            tmp.push(make_pair(num++, head->val));
            head = head->next;
        }
        return res;
    }
};

// faster version
class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
        //将链表放入结果数组
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        stack<int> stack;

        //从右往左遍历
        for (int i = (int)res.size() - 1; i >= 0; --i)
        {
            int cur = res.at(i); //先暂存当前元素
            while (!stack.empty() && cur >= stack.top()) //注意: 等于号不能少 等于时也需要出栈 这里是找严格大于的数
            {
                stack.pop();  //淘汰小的 留下更大的
            }
            res.at(i) = stack.empty() ? 0 : stack.top(); //栈空 右边没有更大的
            stack.push(cur);
        }
        return res;
    }
};