#define _CRT_SECURE_NO_WARNINGS 1

// https://leetcode.cn/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int ret = n + 1;
        while (right < n)
        {
            sum += nums[right];
            while (sum >= target)
            {
                ret = min(ret, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        return ret == n + 1 ? 0 : ret;
    }
};