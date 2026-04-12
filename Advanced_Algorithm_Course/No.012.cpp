// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        int sum = 0;
        for (auto e : nums) sum += e;
        int target = sum - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int left = 0;
        int right = 0;
        int part_sum = 0;
        int ret = -1;
        while (right < nums.size())
        {
            part_sum += nums[right];

            while (part_sum > target)
            {
                part_sum -= nums[left++];
            }

            if (part_sum == target)
                ret = max(ret, right - left + 1);

            right++;
        }
        return ret == -1 ? -1 : nums.size() - ret;
    }
};

int main()
{
    Solution su;
    vector<int> v({ 1,1,4,2,3 });
    int k = 5;
    su.minOperations(v, k);
    return 0;
}