#define _CRT_SECURE_NO_WARNINGS 1

//https://leetcode.cn/problems/valid-triangle-number/

class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        // 1. 优化
        sort(nums.begin(), nums.end());

        // 2. 利用双指针解决问题
        int ret = 0, n = nums.size();
        for (int i = n - 1; i >= 2; i--) // 先固定最⼤的数
        {
            // 利用双指针快速统计符合要求的三元组的个数
            int left = 0, right = i - 1;
            while (left < right) 
            {
                if (nums[left] + nums[right] > nums[i]) 
                {
                    ret += right - left;
                    right--;
                }
                else 
                {
                    left++;
                }
            }
        }
        return ret;
    }
};