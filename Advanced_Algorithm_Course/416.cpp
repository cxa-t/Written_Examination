// https://leetcode.cn/problems/partition-equal-subset-sum/


class Solution
{
public:
    bool canPartition(vector<int>& nums)                         // 判断数组是否能分成两个元素和相等的子集
    {
        int target = 0;                                         // 保存数组所有元素的总和
        for (int e : nums) target += e;                           // 累加得到数组总和
        if (target % 2 == 1) return false;                        // 总和为奇数时无法平分成两个相等子集
        target /= 2;                                            // 将问题转化为能否凑出总和一半
        int m = nums.size();                                     // 获取数组中的元素个数
        vector<vector<bool>> dp(m + 1, vector<bool>(target + 1)); // dp[i][j]表示前i个数能否凑出和j
        for (int i = 0; i <= m; i++) dp[i][0] = true;             // 凑出和0始终可以通过一个元素都不选实现
        for (int i = 1; i <= m; i++)                              // 依次考虑每一个数字
        {
            for (int j = 0; j <= target; j++)                     // 枚举当前需要凑出的目标和
            {
                dp[i][j] = dp[i - 1][j];                           // 不选择第i个数字时继承上一层结果
                if (j >= nums[i - 1])                               // 当前目标和能够容纳第i个数字
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // 判断选择第i个数字后能否凑出当前和
            }
        }
        return dp[m][target];                                    // 返回所有数字能否凑出总和的一半
    }
};