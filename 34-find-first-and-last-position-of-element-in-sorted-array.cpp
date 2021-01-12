/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
- 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ran(2, -1);
        if(nums.size() == 1)
        {
            if(nums[0] == target) return vector<int>({0,0});
            else return ran;
        }
        int left = 0;
        int right = nums.size();
        int mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] >= target) right = mid ;
            else left = mid +1;
        }

        if(left == nums.size() || nums[left] != target) return ran;

        ran[0] = left;

        left = 0;
        right = nums.size()-1;

        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] > target) right = mid;
            else left = mid +1;
        }
        if(nums[right] != target)ran[1] = right-1 ;
        else ran[1] = right;
        return ran;
    }
};