// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int x = nums[right];
        while (left < right)
        {
            // [   ] []
            int mid = left + (right - left) / 2;
            if (nums[mid] < x) right = mid;
            else left = mid + 1;
        }
        return nums[left];
    }
};