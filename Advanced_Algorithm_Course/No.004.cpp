#define _CRT_SECURE_NO_WARNINGS 1

// https://leetcode.cn/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        // ¶Ô×²Ö¸Õë
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;
        while (left < right)
        {
            int v = min(height[left], height[right]) * (right - left);
            ret = max(v, ret);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ret;
    }
};
