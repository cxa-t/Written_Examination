// https://leetcode.cn/problems/permutations/


class Solution
{
public:
    // ret 用来保存所有全排列结果
    vector<vector<int>> ret;
    // check[i] 表示 nums[i] 在当前排列中是否已经被使用
    bool check[7];
    // dfs 用来构造当前排列，path 表示当前已经选择的数字序列
    void dfs(vector<int>& nums, vector<int> path)
    {
        // 如果当前路径长度等于 nums 长度，说明已经形成一个完整排列
        if (path.size() == nums.size())
        {
            // 将当前完整排列加入结果集
            ret.push_back(path);
            // 当前递归结束，返回上一层
            return;
        }
        // 枚举 nums 中的每一个位置
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前位置的数字还没有被使用过
            if (check[i] != true)
            {
                // 将 nums[i] 加入当前排列
                path.push_back(nums[i]);
                // 标记 nums[i] 已经被使用
                check[i] = true;
                // 继续递归选择下一个数字
                dfs(nums, path);
                // 回溯：取消 nums[i] 的使用状态
                check[i] = false;
                // 回溯：删除刚才加入 path 的 nums[i]
                path.pop_back();
            }
        }
    }
    // 返回 nums 的所有全排列
    vector<vector<int>> permute(vector<int>& nums)
    {
        // 如果 nums 为空，直接返回空结果
        if (nums.size() == 0) return ret;
        // path 用来保存当前正在构造的排列
        vector<int> path;
        // 从空路径开始搜索所有排列
        dfs(nums, path);
        // 返回所有全排列结果
        return ret;
    }
};