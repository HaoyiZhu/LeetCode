# 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
# 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        res_list = ['' for _ in range(numRows)]
        row = 0
        direction = 1
        for i in range(len(s)):
            res_list[row] += s[i]
            if direction == 1:
                row += 1
            if direction == -1:
                row -= 1
            if row >= numRows:
                row -= 2
                direction = -1
            if row < 0:
                row += 2
                direction = 1
        res = ''
        for l in res_list:
            res = res + l
        return res
