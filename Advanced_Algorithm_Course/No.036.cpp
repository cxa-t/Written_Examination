//https://leetcode.cn/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (int e : nums)
            {
                if (((e >> i) & 1) == 1)
                {
                    sum++;
                }
            }
            sum %= 3;
            if (sum == 1)
                ret |= (1 << i);
        }
        return ret;

    }
};