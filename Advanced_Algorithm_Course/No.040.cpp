// https://leetcode.cn/problems/zigzag-conversion/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ret;
        int d = 2 * numRows - 2;
        int n = s.size();
        if (d == 0) return s;//d为0代表不需要重新排列，它就是排成一行
        //0   6   12
        //a   g   m
        //1  57  11 
        //b  fh  l
        //2 4 8 10
        //c e i j
        //3   9
        //d   j
        //可以看见第一行最后一行两元素之间的间隔都是d
        //而中间的行数都是以两个为单位进行周期运动的
        //这里只有numRows为1时有问题，但是提前处理过了，所以都ok

        //首行
        for (int i = 0; i < n; i += d) ret += s[i];
        //中间行
        for (int k = 1; k < numRows - 1; k++)//遍历中间的每一行
        {
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
            {
                if (i < n) ret += s[i];
                if (j < n) ret += s[j];
            }
        }
        //尾行
        for (int i = numRows - 1; i < n; i += d) ret += s[i];
        return ret;
    }
};