// https://leetcode.cn/problems/removing-stars-from-a-string/

//遇到普通字符：加入 ret
//遇到 '*'：删除 ret 最后一个字符
class Solution
{
public:
    // 删除字符串中的星号，并删除星号左边最近的一个字符
    string removeStars(string s)
    {
        // ret 用来保存最终处理后的字符串
        string ret;
        // 依次遍历字符串 s 中的每一个字符
        for (char c : s)
        {
            // 如果当前字符是星号，说明要删除前一个字符
            if (c == '*')
            {
                // 如果 ret 不为空，就删除最后一个字符
                if (!ret.empty())
                    ret.pop_back();
            }
            // 如果当前字符不是星号，就加入结果字符串
            else
            {
                // 将当前普通字符加入 ret
                ret.push_back(c);
            }
        }
        // 返回删除星号后的最终字符串
        return ret;
    }
};