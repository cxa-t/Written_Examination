// https://leetcode.cn/problems/single-number-iii/

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> ret(2, 0);
        size_t check = 0;
        for (auto e : nums) check ^= e;
        // 此时的check就是只出现一次的两个数字的按位异或的结果
        //这时候采用按位异或结果的最低位1（因为必有一个0 一个1）
        //分成两组，同组除了最后的结果都是出现两次，按位异或结果为0
        //最后分组完成后就是两组剩下的唯一那个数字。
        int lowbit = check & (-check);
        for (int i = 0; i < nums.size(); i++)
        {
            if (lowbit & nums[i]) ret[0] ^= nums[i];
            else ret[1] ^= nums[i];
        }
        return ret;
    }
};