// https://leetcode.cn/problems/delete-and-earn/

//选择数字 i，就不能选择 i - 1 和 i + 1
//所以这题可以转化为
//数字 i 就像第 i 间房子
//arr[i] 就像偷第 i 间房子能获得的钱
//相邻数字不能同时选，就等价于相邻房子不能同时偷
//状态转移就是：
//f[i] = g[i - 1] + arr[i]          // 选当前数字 i
//g[i] = max(f[i - 1], g[i - 1])    // 不选当前数字 i
class Solution
{
public:
    // 计算删除并获得点数的最大得分
    int deleteAndEarn(vector<int>& nums)
    {
        // N 表示数字范围，因为 nums[i] 最大一般不超过 10000
        const int N = 10001;
        // arr[i] 表示选择数字 i 时，可以获得的总点数
        int arr[N] = { 0 };
        // 遍历 nums 数组，统计每个数字能贡献的总点数
        for (int i = 0; i < nums.size(); i++)
            // 数字 nums[i] 出现一次，就给 arr[nums[i]] 加上 nums[i]
            arr[nums[i]] += nums[i];

        // f[i] 表示选择数字 i 时，在 0 到 i 范围内能获得的最大点数
        vector<int> f(N);
        // g[i] 表示不选择数字 i 时，在 0 到 i 范围内能获得的最大点数
        vector<int> g(N);
        // 从数字 1 开始遍历到 10000
        for (int i = 1; i < N; i++)
        {
            // 如果选择数字 i，那么数字 i-1 不能选择
            f[i] = g[i - 1] + arr[i];
            // 如果不选择数字 i，那么数字 i-1 可选可不选，取最大值
            g[i] = max(g[i - 1], f[i - 1]);
        }
        // 返回最后一个数字选或不选两种情况中的最大值
        return max(f[N - 1], g[N - 1]);
    }
};