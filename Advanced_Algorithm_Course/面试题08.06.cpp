// https://leetcode.cn/problems/hanota-lcci/


class Solution
{
public:
    // 将 a 柱上的所有盘子移动到 c 柱上
    void hanota(vector<int>& a, vector<int>& b, vector<int>& c)
    {
        // 调用递归函数，移动 a.size() 个盘子
        dfs(a, b, c, a.size());
    }

    // 将 a 上的 n 个盘子，借助 b，移动到 c
    void dfs(vector<int>& a, vector<int>& b, vector<int>& c, int n)
    {
        // 如果只剩 1 个盘子，直接从 a 移动到 c
        if (n == 1)
        {
            // 将 a 顶部盘子放到 c 顶部
            c.push_back(a.back());
            // 删除 a 顶部已经移动走的盘子
            a.pop_back();
            // 当前递归结束
            return;
        }

        // 先将 a 上面的 n-1 个盘子，借助 c，移动到 b
        dfs(a, c, b, n - 1);
        // 将 a 剩下的最大盘子移动到 c
        c.push_back(a.back());
        // 删除 a 顶部已经移动走的最大盘子
        a.pop_back();
        // 再将 b 上的 n-1 个盘子，借助 a，移动到 c
        dfs(b, a, c, n - 1);
    }
};