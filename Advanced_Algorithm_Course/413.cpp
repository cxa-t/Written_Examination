// https://leetcode.cn/problems/arithmetic-slices/


class Solution
{
public:
    // 计算数组中等差子数组的数量
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        // n 表示数组长度
        int n = nums.size();
        // 如果数组长度小于 3，不可能形成等差子数组
        if (n < 3) return 0;
        // dp[i] 表示以 nums[i] 结尾的等差子数组数量
        vector<int> dp(n);
        // 前两个位置无法形成长度至少为 3 的等差子数组
        dp[0] = dp[1] = 0;
        // ret 用来记录等差子数组的总数量
        int ret = 0;
        // 从下标 2 开始判断，因为等差子数组至少需要 3 个数
        for (int i = 2; i < n; i++)
        {
            // 如果 nums[i-2]、nums[i-1]、nums[i] 构成等差关系，则 dp[i] = dp[i-1] + 1
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            // 将以 nums[i] 结尾的等差子数组数量加入答案
            ret += dp[i];
        }
        // 返回所有等差子数组的数量
        return ret;
    }
};