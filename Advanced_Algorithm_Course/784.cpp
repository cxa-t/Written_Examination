// https://leetcode.cn/problems/letter-case-permutation/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> ret;                         // 保存所有大小写排列结果
    string path;                                // 保存当前正在构造的字符串

    void dfs(string& s, int pos)                // pos表示当前需要处理的字符位置
    {
        if (pos == s.size())                     // 所有字符都已经处理完成
        {
            ret.push_back(path);                // 将当前字符串加入结果集
            return;                             // 当前递归分支结束
        }

        if (isalpha(s[pos]))                     // 当前字符是字母
        {
            path += toupper(s[pos]);            // 当前字母选择大写形式
            dfs(s, pos + 1);                    // 继续处理下一个字符
            path.pop_back();                    // 回溯，撤销大写字符

            path += tolower(s[pos]);            // 当前字母选择小写形式
            dfs(s, pos + 1);                    // 继续处理下一个字符
            path.pop_back();                    // 回溯，撤销小写字符
        }
        else                                    // 当前字符是数字
        {
            path += s[pos];                     // 数字没有大小写，直接加入当前字符串
            dfs(s, pos + 1);                    // 继续处理下一个字符
            path.pop_back();                    // 回溯，撤销当前数字
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        dfs(s, 0);                              // 从第0个字符开始进行搜索
        return ret;                             // 返回所有大小写排列结果
    }
};


int main()
{
    string s = "a1b2";
    Solution().letterCasePermutation(s);
    return 0;
}