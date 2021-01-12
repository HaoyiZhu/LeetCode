// 给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

// Sliding Window + unordered_set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashset;
        int r = -1;
        int len = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if(i > 0) hashset.erase(s[i-1]);
            while(r+1 < n && !hashset.count(s[r+1]))
            {
                hashset.insert(s[r+1]);
                r++;
            }
            len = max(len, r - i + 1);
        }
        return len;
    }
};