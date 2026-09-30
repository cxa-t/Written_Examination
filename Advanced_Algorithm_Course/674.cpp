// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/


class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums) // 返回数组中最长连续严格递增子序列的长度
    {
        int n = nums.size(); // 获取数组长度
        int ret = 0; // 记录目前找到的最长连续递增子序列长度
        int i = 0; // i 表示当前连续递增子序列的起始位置
        while (i < n) // 只要起始位置还没有越过数组末尾，就继续寻找下一段连续递增序列
        {
            int j = i + 1; // j 从 i 的下一个位置开始，用来向后寻找连续递增区间的终点
            while (j < n && nums[j] > nums[j - 1]) j++; // 如果当前元素比前一个元素大，说明仍然保持严格递增，j 继续向后移动
            ret = max(ret, j - i); // 当前连续递增区间为 [i,j-1]，长度为 j-i，用它更新最大长度
            i = j; // 当前递增区间已经结束，让 i 跳到下一段区间的起始位置继续查找
        }
        return ret; // 返回最长连续严格递增子序列的长度
    }
};