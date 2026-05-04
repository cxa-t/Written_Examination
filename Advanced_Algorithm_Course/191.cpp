// https://leetcode.cn/problems/number-of-1-bits/

class Solution
{
public:
    int hammingWeight(int n)
    {
        // //法一：一直以最低位按位与1 得到1的个数
        // int ret = 0;
        // while(n)
        // {
        //     ret += (n & 1);
        //     n >>= 1;
        // }
        // return ret;
        //法二：每次消灭最右边的1
        int ret = 0;
        while (n)
        {
            ret++;
            n &= (n - 1);//n-1作用就是将最低位的1及其右边全部变成相反的，左边不变
        }
        return ret;
    }
};