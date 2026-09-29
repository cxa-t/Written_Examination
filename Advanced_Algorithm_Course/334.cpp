// https://leetcode.cn/problems/increasing-triplet-subsequence/

class Solution
{
public:
    bool increasingTriplet(vector<int>& nums) // 判断数组中是否存在满足下标递增且数值严格递增的三个元素
    {
        int a = nums[0]; // 记录当前找到的最小元素，作为递增三元组中的第一个数
        int b = INT_MAX; // 记录在 a 之后找到的较小的第二个元素，初始设为最大整数
        for (int i = 1; i < nums.size(); i++) // 从第二个元素开始遍历数组
        {
            if (nums[i] > b) return true; // 如果当前元素比第二个元素 b 还大，说明已经找到 a < b < nums[i]，直接返回 true
            else if (nums[i] > a) b = nums[i]; // 当前元素大于 a 但不大于 b，用它更新 b，使第二个元素尽可能小，更容易在后面找到第三个更大的元素
            else a = nums[i]; // 当前元素小于等于 a，更新 a，使第一个元素尽可能小，为后续组成递增三元组提供更多可能
        }
        return false; // 遍历结束仍未找到三个严格递增的元素，返回 false
    }
};