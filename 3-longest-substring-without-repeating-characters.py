'''
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m = {}
        start = -1
        cur_len = 0
        for i, string in enumerate(s):
            if string in m and start < m[string]:	# 当前字符已出现过，且上次出现在start之后 -> 更新当前字符上次出现位置，并重新开始
                start = m[string]
                m[string] = i
            else:
                m[string] = i
                cur_len = max(cur_len, i-start)
        return cur_len