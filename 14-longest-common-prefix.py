'''
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
'''

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        res = ""
        idx = 0
        max_len = min([len(string) for string in strs])
        while True:
            if idx >= max_len:
                break
            s = list(set([string[idx] for string in strs]))
            if len(s) > 1:
                break
            else:
                res += s[0]
                idx += 1
        return res