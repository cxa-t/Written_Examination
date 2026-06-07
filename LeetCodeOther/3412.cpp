// https://leetcode.cn/problems/find-mirror-score-of-a-string/

//遇到一个字符时，先看前面有没有它的镜像字符；
//如果有，就配对并加上下标距离；如果没有，就把当前字符的位置存起来。
class Solution
{
public:
    // 计算字符串中镜像字符配对后的总得分
    long long calculateScore(string s)
    {
        // st[i] 存放第 i 个字母还没有被匹配的位置下标
        stack<int> st[26];
        // ret 用来记录最终得分，建议用 long long 更符合返回值类型
        long long ret = 0;

        // 从左到右遍历字符串中的每个字符
        for (int i = 0; i < s.size(); i++)
        {
            // c 表示当前字符在字母表中的编号，a 是 0，b 是 1
            int c = s[i] - 'a';
            // 25 - c 表示当前字符的镜像字符编号，比如 a 对 z，b 对 y
            if (!st[25 - c].empty())
            {
                // 如果前面存在镜像字符，就把当前位置和镜像字符位置的距离加入答案
                ret += i - st[25 - c].top();
                // 当前字符已经和这个镜像字符配对，所以弹出该镜像字符位置
                st[25 - c].pop();
            }
            // 如果前面没有可以匹配的镜像字符
            else
            {
                // 将当前字符的位置存入对应字符的栈中，等待后面匹配
                st[c].push(i);
            }
        }
        // 返回最终得分
        return ret;
    }
};