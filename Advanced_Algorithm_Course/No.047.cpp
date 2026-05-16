// https://leetcode.cn/problems/sort-an-array/


//思路：
//这里需要注意，每次合并两个有序数组的时候，如果直接开原排序数组那么大的话
//会直接超时（验证了），但是只开当前区间这么大的辅助数组，就不会超时（验证了）
//归并就是归并最小的区间，然后还原到原数组，相当于二叉树的后序。
class Solution
{
public:
    //vector<int> tmp;
    vector<int> sortArray(vector<int>& nums)
    {
        //tmp.resize(nums.size());
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        vector<int> tmp(right - left + 1);//
        int cur1 = left;
        int cur2 = mid + 1;
        //int i = left;
        int i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            tmp[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++];
        }
        while (cur1 <= mid) tmp[i++] = nums[cur1++];
        while (cur2 <= right) tmp[i++] = nums[cur2++];
        int k = 0;
        for (int i = left; i <= right; i++) nums[i] = tmp[k++];
    }
};