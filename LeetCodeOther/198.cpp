// https://leetcode.cn/problems/house-robber/


class Solution
{
public:
    // 计算在不能偷相邻房子的情况下，可以偷到的最大金额
    int rob(vector<int>& nums)
    {
        // n 表示房子的数量
        int n = nums.size();
        // dp[i] 表示偷到第 i 个房子时，能够获得的最大金额
        vector<int> dp(n);
        // 如果没有房子，最大金额为 0
        if (n == 0) return 0;
        // 如果只有一个房子，只能偷这个房子
        if (n == 1) return nums[0];
        // 偷到第 0 个房子时，最大金额就是 nums[0]
        dp[0] = nums[0];
        // 偷到第 1 个房子时，只能在第 0 个和第 1 个之间选金额更大的
        dp[1] = max(nums[0], nums[1]);
        // 从第 2 个房子开始递推
        for (int i = 2; i < n; i++)
            // 第 i 个房子可以选择偷或不偷，取两种情况的最大值
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        // 返回偷到最后一个房子时的最大金额
        return dp[n - 1];
    }
};