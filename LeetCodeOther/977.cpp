// https://leetcode.cn/problems/squares-of-a-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ret(n, 0);
        int left = 0;
        int right = n - 1;
        int k = n - 1;
        while (left < right)
        {
            while (left < right && abs(nums[left]) <= abs(nums[right]))
            {
                ret[k--] = nums[right] * nums[right];
                right--;
            }
            while (left < right && abs(nums[right]) < abs(nums[left]))
            {
                ret[k--] = nums[left] * nums[left];
                left++;
            }
        }
        if (left == right) ret[k] = nums[left] * nums[left];
        return ret;
    }
};

int main()
{
    vector<int> nums = { -7,-3,2,3,11 };
    Solution().sortedSquares(nums);
    return 0;
}