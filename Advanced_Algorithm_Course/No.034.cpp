//https://leetcode.cn/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ret = 0;
        int yuan = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ret ^= i;
            yuan ^= nums[i];
        }
        ret ^= nums.size();
        return ret ^ yuan;
    }
};