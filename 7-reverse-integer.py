'''
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

注意：
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
'''

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            sign = -1
        else:
            sign = 1
        res =  sign * (int(str(abs(x))[::-1]))
        if -2**31 <= res <= 2**31-1:
            return res
        else:
            return 0