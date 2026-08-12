// https://leetcode.cn/problems/beautiful-arrangement/


class Solution
{
    bool check[16];                         // 标记数字i是否已经被使用
    int ret;                                // 记录满足优美排列条件的方案数量

public:
    int countArrangement(int n)             // 统计1到n能够组成的优美排列数量
    {
        dfs(1, n);                          // 从排列的第1个位置开始搜索
        return ret;                         // 返回所有合法排列的数量
    }

    void dfs(int pos, int n)                // pos表示当前需要放置数字的位置
    {
        if (pos == n + 1)                   // 所有位置都已经成功放置数字
        {
            ret++;                          // 找到一个合法排列，方案数加一
            return;                         // 当前搜索分支结束
        }

        for (int i = 1; i <= n; i++)        // 枚举当前位置可以放置的数字
        {
            if (!check[i] && (pos % i == 0 || i % pos == 0)) // 当前数字未使用且满足优美排列条件
            {
                check[i] = true;            // 标记当前数字已经被使用
                dfs(pos + 1, n);            // 继续搜索下一个位置
                check[i] = false;           // 回溯，恢复当前数字为未使用状态
            }
        }
    }
};