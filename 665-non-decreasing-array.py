'''
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
'''
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if len(nums) < 2:
            return True
        thr = 0
        for i in range(len(nums) - 1):
            if (nums[i+1] - nums[i]) >= 0:
                pass
            else:
                thr += 1
                if 0 < i < len(nums) - 2:
                	# 无法恢复
                    '''
                    k_prev = nums[i] - nums[i-1]
                    k = nums[i] - nums[i+1]
                    k_next = nums[i+2] - nums[i+1]
                    if k > k_prev and k > k_next:
                        return False
                    '''
                    if nums[i-1] > nums[i+1] and nums[i] > nums[i+2]:
                        return False
            if thr > 1:
                return False
        return True