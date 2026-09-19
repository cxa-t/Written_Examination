// https://leetcode.cn/problems/combination-sum-iv/

class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)               // 计算和为target的不同有序组合数量
    {
        vector<double> dp(target + 1);                               // dp[i]表示组成数字i的有序组合数量
        dp[0] = 1;                                                   // 组成0有一种空组合方案
        for (int i = 1; i <= target; i++)                             // 从小到大计算每一个目标值的方案数
        {
            for (auto e : nums)                                      // 枚举当前组合最后选择的数字
            {
                if (e <= i)                                          // 当前数字不能超过需要组成的目标值
                    dp[i] += dp[i - e];                                // 累加以当前数字e结尾的所有组合方案
            }
        }
        return dp[target];                                           // 返回组成target的所有有序组合数量
    }
};
