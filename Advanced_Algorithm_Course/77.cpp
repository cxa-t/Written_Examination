// https://leetcode.cn/problems/combinations/


class Solution
{
public:
    int k = 0;                          // 记录需要选择的元素个数
    vector<vector<int>> ret;            // 保存所有满足条件的组合
    vector<int> path;                   // 保存当前正在构造的组合
    int n = 0;                          // 记录数字范围的最大值 n

    void dfs(int start)                 // 从 start 开始选择数字进行回溯
    {
        if (path.size() == k)            // 当前组合中已经选够 k 个数字
        {
            ret.push_back(path);        // 将当前组合加入结果集
            return;                     // 当前组合完成，结束本层搜索
        }

        for (int i = start; i <= n; i++) // 从 start 到 n 依次尝试选择数字
        {
            path.push_back(i);          // 选择当前数字 i 加入组合
            dfs(i + 1);                 // 从 i+1 开始继续选择下一个数字
            path.pop_back();            // 撤销当前选择，进行回溯
        }
    }

    vector<vector<int>> combine(int _n, int _k)
    {
        n = _n;                         // 保存题目给定的数字范围 n
        k = _k;                         // 保存题目要求选择的数字个数 k
        dfs(1);                         // 从数字 1 开始进行深度优先搜索
        return ret;                     // 返回所有满足条件的组合
    }
};