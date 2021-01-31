# 给你一个字符串 s，找到 s 中最长的回文子串。

# O(n)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1 or s == s[::-1]:
            return s
        head = 1
        cur_len = 1
        for i in range(1, len(s)):
            ss1 = s[i-cur_len : i+1]
            ss2 = s[i-cur_len-1 : i+1]
            if i - cur_len >= 0 and ss1 == ss1[::-1]:
                head = i - cur_len
                cur_len += 1
                continue
            if i - cur_len - 1 >= 0 and ss2 == ss2[::-1]:
                head = i - cur_len - 1
                cur_len += 2
        return s[head: head+cur_len]