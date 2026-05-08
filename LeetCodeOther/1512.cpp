// https://leetcode.cn/problems/number-of-good-pairs/

class Solution
{
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        //只需要求出相等的数对个数就可以
        //暴力就是固定左端，然后遍历找右端
        //优化之后就是使用hash存左端数字出现的个数，右端直接加上相应左端数字的个数
        //注意你需要先维护结果，再维护hash
        //一个简单的例子：1 
        //如果你先维护hash，很明显结果会被多加一个它自己本身，而不是有效数对
        unordered_map<int, int> hash;
        int ret = 0;
        for (auto e : nums)
        {
            ret += hash[e];
            hash[e]++;
        }
        return ret;
    }
};