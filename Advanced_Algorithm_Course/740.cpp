// https://leetcode.cn/problems/delete-and-earn/


//选择数字 i，就不能选择 i - 1 和 i + 1
//所以这题可以转化为
//数字 i 就像第 i 间房子
//arr[i] 就像偷第 i 间房子能获得的钱
//相邻数字不能同时选，就等价于相邻房子不能同时偷
//状态转移就是：
//f[i] = g[i - 1] + arr[i]          // 选当前数字 i
//g[i] = max(f[i - 1], g[i - 1])    // 不选当前数字 i
class Solution {
public:
    // 删除并获得点数，本质上可以转化为“打家劫舍”问题
    int deleteAndEarn(vector<int>& nums) {
        // N 表示数字的最大范围，这里 nums[i] 最大不超过 10000
        const int N = 10001;
        // arr[i] 表示把所有数字 i 都选中后，可以获得的总点数
        int arr[N] = { 0 };
        // 遍历 nums，把相同数字的点数累加到 arr[x] 中
        for (auto x : nums)
            // 如果选择数字 x，每出现一次就可以获得 x 分
            arr[x] += x;
        // f[i] 表示选择数字 i 时，在 0 到 i 范围内能获得的最大点数
        vector<int> f(N);
        // g[i] 表示不选择数字 i 时，在 0 到 i 范围内能获得的最大点数
        auto g = f;
        // 从数字 1 开始遍历到 10000
        for (int i = 1; i < N; i++) {
            // 如果选择数字 i，那么数字 i-1 不能选
            f[i] = g[i - 1] + arr[i];
            // 如果不选择数字 i，那么数字 i-1 可选可不选，取最大值
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 最终答案是最后一个数字选或不选两种情况的最大值
        return max(f[N - 1], g[N - 1]);
    }
};