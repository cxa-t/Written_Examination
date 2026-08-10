// https://leetcode.cn/problems/combination-sum/

//法一
class Solution
{
public:
    vector<vector<int>> ret;                         // 保存所有满足条件的组合
    vector<int> path;                                // 保存当前正在构造的组合
    int target = 0;                                  // 保存目标值

    void dfs(vector<int>& candidates, int pos, int sum) // pos表示起始位置，sum表示当前组合和
    {
        if (sum == target)                            // 当前组合和等于目标值
        {
            ret.push_back(path);                     // 将当前组合加入结果集
            return;                                  // 当前分支搜索结束
        }

        if (sum > target) return;                     // 当前组合和超过目标值，直接剪枝

        for (int i = pos; i < candidates.size(); i++) // 从pos位置开始枚举可选择的数字
        {
            path.push_back(candidates[i]);           // 将当前数字加入组合
            sum += candidates[i];                    // 将当前数字累加到组合和中

            dfs(candidates, i, sum);                 // 当前数字可以重复使用，因此继续从i开始搜索

            sum -= candidates[i];                    // 回溯，恢复选择前的组合和
            path.pop_back();                         // 回溯，删除刚刚加入的数字
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int _target)
    {
        target = _target;                            // 保存题目给定的目标值
        dfs(candidates, 0, 0);                       // 从第0个位置开始搜索，初始组合和为0
        return ret;                                  // 返回所有满足条件的组合
    }
};


// 法二   
class Solution
{
public:
    vector<vector<int>> ret;                          // 保存所有满足条件的组合
    vector<int> path;                                 // 保存当前正在构造的组合
    int target = 0;                                   // 保存目标值

    void dfs(vector<int>& candidates, int pos, int sum) // pos表示当前数字位置，sum表示当前组合和
    {
        if (sum == target)                             // 当前组合和等于目标值
        {
            ret.push_back(path);                      // 将当前组合加入结果集
            return;                                   // 当前分支搜索结束
        }

        if (sum > target || pos == candidates.size())  // 超过目标值或所有数字都已处理则结束搜索
            return;

        int i = 0;                                    // 记录当前数字选择的次数

        for (i = 0; i * candidates[pos] <= target; i++) // 枚举当前数字选择0次、1次、2次……
        {
            if (i)                                     // 当前数字从选择1次开始加入path
                path.push_back(candidates[pos]);      // 将当前数字再加入一次组合

            dfs(candidates, pos + 1,                  // 递归处理下一个候选数字
                sum + i * candidates[pos]);           // 更新选择当前数字i次后的组合和
        }

        for (int j = 1; j < i; j++)                    // 删除本层加入的所有当前数字
        {
            path.pop_back();                          // 回溯恢复进入本层前的path
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int _target)
    {
        target = _target;                             // 保存题目给定的目标值
        dfs(candidates, 0, 0);                        // 从第0个数字开始且初始组合和为0
        return ret;                                   // 返回所有满足条件的组合
    }
};