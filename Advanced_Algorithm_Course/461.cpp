//https://leetcode.cn/problems/hamming-distance/

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int num = x ^ y;
        int ret = 0;
        while (num)
        {
            ret++;
            num &= (num - 1);
        }
        return ret;
    }
};