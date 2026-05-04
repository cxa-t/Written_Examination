// https://leetcode.cn/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ret;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int num = i;
            while (num)
            {
                count++;
                num &= (num - 1);
            }
            ret.push_back(count);
        }
        return ret;
    }
};