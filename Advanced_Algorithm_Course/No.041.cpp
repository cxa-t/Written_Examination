// https://leetcode.cn/problems/count-and-say/description/

class Solution
{
public:
    string countAndSay(int n)
    {
        //思路：
        //规则解读：
        //这里后一个需要把前一个字符串描述出来，n等于1时，就是原生字符串"1"
        //n等于2时就是把n等于1的那个字符串描述出来，"1"就是 1个1 所以n等于2时就是 "11"
        //整体思路就是双指针进行模拟，统计出s[left]的个数，然后加入描述中
        //这个描述后的字符串就是后一个的初始字符串，也就是结果
        string ret = "1";
        for (int i = 1; i < n; i++)
        {
            string tmp;
            int n = ret.size();
            int left = 0;
            int right = 0;
            while (right < n)
            {
                while (ret[right] == ret[left]) right++;
                int count = right - left;
                tmp += count + '0';
                tmp += ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }
};