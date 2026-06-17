// https://leetcode.cn/problems/maximum-subarray/


class Solution
{
public:
    // 计算数组中的最大连续子数组和
    int maxSubArray(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // ret 用来记录最终的最大子数组和，初始值设为很小的数
        int ret = -0x3f3f3f3f;
        // dp[i] 表示以 nums[i - 1] 结尾的最大连续子数组和
        vector<int> dp(n + 1);
        // 从第 1 个位置开始遍历到第 n 个位置
        for (int i = 1; i <= n; i++)
        {
            // 以当前位置结尾时，要么自己单独成段，要么接在前一个子数组后面
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            // 用当前最大连续子数组和更新最终答案
            ret = max(ret, dp[i]);
        }
        // 返回最大连续子数组和
        return ret;
    }
};