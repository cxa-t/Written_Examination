//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0) return { -1, -1 };

        int left = 0, right = nums.size() - 1;
        int begin = 0;
        //寻找左端点
        while (left < right)
        {
            // [ 2 2 2]  3 3 3
            //   l   m       r
            //一直寻找最左边，所以左边需要往出跳
            // [2 2]
            //  l r
            //需要往左靠，所以需要定位靠左的中间元素
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        //当前找到最合理的位置 不是target就表示没有答案
        if (nums[left] != target) return { -1, -1 };
        else begin = left;
        //重新定义 l r
        left = 0;
        right = nums.size() - 1;
        //寻找右端点
        while (left < right)
        {
            // [2 2 2 2] 3 3
            //  l     m    r
            // [2 2 2 2] 3 3 3 3
            //  l        m     r
            //一直寻找最右边，所以右边需要往出跳
            // [2 2]
            //  l r
            //需要往右靠，所以需要定位靠右的中间元素
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        return { begin, right };
    }
};