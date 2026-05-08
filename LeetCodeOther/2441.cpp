// https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/description/

class Solution
{
public:
    int findMaxK(vector<int>& nums)
    {
        //思路：
        //暴力的话就是固定左，寻找右
        //优化就是哈希维护左，到右的时候在哈希寻找左，有结果的话维护结果
        unordered_map<int, int> hash;
        int ret = 0;
        for (int e : nums)
        {
            if (e > 0)
            {
                if (hash.count(-e))
                {
                    ret = max(ret, e);
                }
            }
            else
            {
                //注意：如果是负数的话，你必须要找相反数在不在哈希里，所以是abs(e) 
                if (hash.count(abs(e)))
                {
                    ret = max(ret, abs(e));
                }
            }
            hash[e]++;
        }
        return ret == 0 ? -1 : ret;
    }
};