// https://leetcode.cn/problems/permutations-ii/


class Solution
{
public:
    // ret 用来保存所有不重复的全排列结果
    vector<vector<int>> ret;
    // path 用来保存当前正在构造的排列
    vector<int> path;
    // check[i] 表示 nums[i] 在当前排列中是否已经被使用
    bool check[8];

    // 回溯生成 nums 的所有不重复排列
    void dfs(vector<int>& nums)
    {
        // 如果 path 长度等于 nums 长度，说明形成了一个完整排列
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
            // 如果当前数字已经用过，或者当前数字和前一个数字相同且前一个数字没用过，就跳过
            //上一层  ||  同层同一个数字  不考虑
            if (check[i] || (i > 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
            {
                // 跳过当前不合法选择
                continue;
            }

            // 选择 nums[i] 加入当前排列
            path.push_back(nums[i]);
            // 标记 nums[i] 已经被使用
            check[i] = true;
            // 继续递归选择下一个位置
            dfs(nums);
            // 回溯：取消 nums[i] 的使用状态
            check[i] = false;
            // 回溯：删除刚才加入 path 的 nums[i]
            path.pop_back();
        }
    }

    // 返回 nums 的所有不重复全排列
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        // 先排序，让相同数字相邻，方便后续去重
        sort(nums.begin(), nums.end());
        // 从空排列开始搜索
        dfs(nums);
        // 返回所有不重复排列结果
        return ret;
    }
};