// https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/

class Solution 
{
public:
    int minInsertions(string s)                     // 计算使括号字符串合法所需的最少插入次数
    {
        int n = s.size();                           // 获取字符串长度
        int left = 0;                               // 记录当前还没有匹配的左括号数量
        int ret = 0;                                // 记录需要插入的括号数量
        for(int i = 0; i < n; i++)                  // 从左到右依次遍历字符串
        {
            if(s[i] == '(')                         // 当前字符是左括号
            {
                left++;                             // 增加一个等待匹配的左括号
                continue;                           // 当前左括号处理完成继续遍历
            }
            else                                    // 当前字符是右括号
            {
                if(left > 0) left--;                // 使用一个未匹配左括号与当前右括号进行匹配
                else ret++;                         // 没有左括号时插入一个左括号
                if(i + 1 < n && s[i + 1] == ')') i++; // 后面还有右括号时直接组成连续的两个右括号
                else ret++;                         // 缺少第二个右括号时插入一个右括号
            }
        }
        return ret + left * 2;                      // 每个剩余左括号都需要再补两个右括号
    }
};