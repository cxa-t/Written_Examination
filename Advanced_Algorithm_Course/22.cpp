// https://leetcode.cn/problems/generate-parentheses/


class Solution
{
public:
    // ret 用来保存所有合法的括号组合
    vector<string> ret;
    // left 表示当前已经使用的左括号数量
    int left = 0;
    // right 表示当前已经使用的右括号数量
    int right = 0;
    // n 表示需要生成几对括号
    int n = 0;
    // path 表示当前正在构造的括号字符串
    string path;
    // 回溯生成所有合法括号组合
    void dfs()
    {
        // 如果右括号数量等于 n，说明已经形成一个完整合法组合
        if (n == right)
        {
            // 将当前合法括号组合加入结果集
            ret.push_back(path);
            // 当前递归结束，返回上一层
            return;
        }

        // 如果左括号还没有用完，可以继续添加左括号
        if (left < n)
        {
            // 添加一个左括号
            path += "(";
            // 左括号数量加一
            left++;
            // 继续递归生成后面的括号
            dfs();
            // 回溯：删除刚才添加的左括号
            path.pop_back();
            // 回溯：恢复左括号数量
            left--;
        }
        // 如果右括号数量小于左括号数量，才可以添加右括号
        if (right < left)
        {
            // 添加一个右括号
            path += ")";
            // 右括号数量加一
            right++;
            // 继续递归生成后面的括号
            dfs();
            // 回溯：删除刚才添加的右括号
            path.pop_back();
            // 回溯：恢复右括号数量
            right--;
        }
    }
    // 生成 num 对括号的所有合法组合
    vector<string> generateParenthesis(int num)
    {
        // 如果 num 为 0，直接返回空结果
        if (num == 0) return ret;
        // 记录需要生成的括号对数
        n = num;
        // 从空字符串开始回溯搜索
        dfs();
        // 返回所有合法括号组合
        return ret;
    }
};