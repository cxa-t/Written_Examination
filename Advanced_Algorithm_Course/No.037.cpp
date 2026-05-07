// https://leetcode.cn/problems/missing-two-lcci/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        //思路：
        //也是少两个，但是其他的只出现一次，那么我们可以让他出现两次
        //所以不仅按位异或数组元素，也要按位异或 1 - N+2 这些数字
        //按位异或完就提取二进制的最低位1，然后根据与lowbit按位异或的结果继续给这些数字分组
        //按位异或为1的话，必然一个1一个0，所以这一定是两个答案（其余出现两次，结果必为0）
        //完了就给每个分组按位异或，就得到两个答案
        vector<int> ret(2, 0);
        int n = nums.size();
        size_t check = 0;
        for (int i = 1; i < n + 3; i++)
        {
            if (i < n + 1)
            {
                check ^= i;
                check ^= nums[i - 1];
            }
            else check ^= i;
        }
        int lowbit = check & (-check);
        for (int i = 1; i < n + 3; i++)
        {
            if (i < n + 1)
            {
                if (lowbit & i) ret[0] ^= i;
                else ret[1] ^= i;
                if (lowbit & nums[i - 1]) ret[0] ^= nums[i - 1];
                else ret[1] ^= nums[i - 1];
            }
            else
            {
                if (lowbit & i) ret[0] ^= i;
                else ret[1] ^= i;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = { 1 };
    Solution().missingTwo(nums);
    return 0;
}