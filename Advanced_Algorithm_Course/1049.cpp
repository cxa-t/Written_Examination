// https://leetcode.cn/problems/last-stone-weight-ii/

class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)                       // 计算所有石头碰撞后可能剩下的最小重量
    {
        int sum = 0;                                                  // 保存所有石头的总重量
        for (int e : stones) sum += e;                                 // 累加得到石头总重量
        int goal = sum / 2;                                           // 将问题转化为尽量凑接近总重量一半的子集
        int n = stones.size();                                        // 获取石头的数量
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1));         // dp[i][j]表示前i块石头在容量j内能凑出的最大重量
        for (int i = 1; i <= n; i++)                                  // 依次考虑每一块石头
        {
            for (int j = 0; j <= goal; j++)                            // 枚举当前背包容量
            {
                dp[i][j] = dp[i - 1][j];                                // 不选择当前石头时继承上一层结果
                if (j >= stones[i - 1])                                // 当前容量能够放下第i块石头
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]); // 比较选择和不选择当前石头的最大重量
            }
        }
        return sum - 2 * dp[n][goal];                                 // 用两组石头重量差得到最终最小剩余重量
    }
};


class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)                       // 计算所有石头碰撞后可能剩下的最小重量
    {
        int sum = 0;                                                  // 保存所有石头的总重量
        for (int e : stones) sum += e;                                 // 累加得到所有石头的总重量
        int goal = sum / 2;                                           // 将问题转化为尽量凑出接近总重量一半的子集
        int n = stones.size();                                        // 获取石头的数量
        vector<int> dp(goal + 1);                                     // dp[j]表示容量j内能够凑出的最大石头重量
        for (int i = 1; i <= n; i++)                                  // 依次考虑每一块石头
        {
            for (int j = goal; j >= 0; j--)                            // 倒序枚举容量保证每块石头只使用一次
            {
                if (j >= stones[i - 1])                                // 当前容量能够放下第i块石头
                    dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]); // 比较选择和不选择当前石头的最大重量
            }
        }
        return sum - 2 * dp[goal];                                    // 用两组石头的最小重量差得到最终答案
    }
};