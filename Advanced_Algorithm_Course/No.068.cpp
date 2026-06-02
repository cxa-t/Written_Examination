// https://leetcode.cn/problems/decode-string/


//数字栈 numst 存重复次数
//字符串栈 strst 存每一层括号里的字符串
//遇到 ']' 时，把当前层字符串重复后拼接回上一层
#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution
{
public:
    // 解码形如 "3[a2[c]]" 这种编码字符串
    string decodeString(string s)
    {
        // n 表示字符串长度
        int n = s.size();
        // 数字栈，用来存储每一层括号前面的重复次数
        stack<int> numst;
        // 字符串栈，用来存储每一层括号中的字符串
        stack<string> strst;
        // 先放入一个空字符串，作为最外层结果
        strst.push("");

        // i 表示当前遍历到的字符串下标
        int i = 0;
        // 从左到右遍历整个字符串
        while (i < n)
        {
            // 如果当前字符是数字，就解析完整的重复次数
            if (s[i] >= '0' && s[i] <= '9')
            {
                // tmp 用来保存当前解析出的数字
                int tmp = 0;
                // 连续读取多位数字
                while (s[i] >= '0' && s[i] <= '9')
                {
                    // 将字符数字转换成整数并累加到 tmp 中
                    tmp = tmp * 10 + (s[i] - '0');
                    // 继续读取下一位字符
                    i++;
                }
                // 将当前重复次数压入数字栈
                numst.push(tmp);
            }

            // 如果遇到左括号，说明进入了一层新的编码结构
            else if (s[i] == '[')
            {
                // 跳过左括号 '['
                i++;
                // tmp 用来保存当前括号内开头的普通字符串
                string tmp;
                // 读取左括号后面连续的小写字母
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    // 将当前字符加入 tmp
                    tmp += s[i];
                    // 继续读取下一位字符
                    i++;
                }
                // 将当前层字符串压入字符串栈
                strst.push(tmp);
            }
            // 如果遇到右括号，说明当前层编码结束
            else if (s[i] == ']')
            {
                // 取出当前层需要重复的次数
                int count = numst.top();
                // 弹出已经使用过的重复次数
                numst.pop();
                // 取出当前层括号内的字符串
                string str = strst.top();
                // 弹出当前层字符串
                strst.pop();
                // 将当前字符串重复 count 次，追加到上一层字符串后面
                while (count--) strst.top() += str;
                // 跳过右括号 ']'
                i++;
            }
            // 如果当前字符是普通字母，直接加入当前层字符串
            else
            {
                // tmp 用来保存连续的普通字母
                string tmp;
                // 连续读取小写字母
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    // 将当前字符加入 tmp
                    tmp += s[i];
                    // 继续读取下一位字符
                    i++;
                }
                // 将普通字符串追加到当前层字符串后面
                strst.top() += tmp;
            }
        }
        // 栈顶就是最终解码后的完整字符串
        return strst.top();
    }
};

int main()
{
    string s = "100[leetcode]";
    Solution().decodeString(s);
    return 0;
}