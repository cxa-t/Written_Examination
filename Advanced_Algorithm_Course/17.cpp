// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/


class Solution
{
public:
    // 用 vector<string> 保存数字到字母的映射关系
    vector<string> hash = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    // path 保存当前正在构造的字母组合
    string path;
    // ret 保存所有最终的字母组合
    vector<string> ret;

    // dfs 表示正在处理 digits[pos] 这个数字
    void dfs(string& digits, int pos)
    {
        // 如果 path 长度等于 digits 长度，说明已经形成一个完整组合
        if (path.size() == digits.size())
        {
            // 将当前完整组合加入结果集
            ret.push_back(path);
            // 当前递归结束，返回上一层
            return;
        }

        // 遍历当前数字对应的所有字母
        for (auto& e : hash[digits[pos] - '0'])
        {
            // 选择当前字母加入 path
            path.push_back(e);
            // 继续处理下一个数字
            dfs(digits, pos + 1);
            // 回溯：撤销刚才选择的字母
            path.pop_back();
        }
    }

    // 返回电话号码 digits 对应的所有字母组合
    vector<string> letterCombinations(string digits)
    {
        // 如果 digits 为空，直接返回空结果
        if (digits.size() == 0) return ret;
        // 从第 0 个数字开始搜索
        dfs(digits, 0);
        // 返回所有组合结果
        return ret;
    }
};