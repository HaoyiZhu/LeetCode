/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i, j;
        int n = nums.size();
        vector<int> dp(n,0);

        if(n==0) return 0;
        for(i=0; i<n; i++)
        {
            dp[i] = 1;
            for(j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {dp[i] = max(dp[i], dp[j]+1);
            }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
