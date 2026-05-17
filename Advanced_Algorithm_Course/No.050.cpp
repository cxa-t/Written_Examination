// https://leetcode.cn/problems/reverse-pairs/

#include<iostream>
#include<vector>
using namespace std;

// 思路
// 这里一定不能边归并边计数
// 5 4 3 2 1
// [5,4,3] [2,1]
//当你在5时可以做到边归并边计数，但是到4的时候，4 == 2*2
//但是此时你已经不满足第一个条件了，所以你如果直接归并下来的话，会少计数一个
//所以只能把计数和归并分开
class Solution
{
public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        int ret = 0;
        vector<int> auxnums(n, 0);
        mergesort(nums, 0, n - 1, ret, auxnums);
        return ret;
    }
    void mergesort(vector<int>& nums, int left, int right, int& ret, vector<int>& auxnums)
    {
        if (left >= right) return;

        int mid = (left + right) >> 1;
        mergesort(nums, left, mid, ret, auxnums);
        mergesort(nums, mid + 1, right, ret, auxnums);

        //降序
        int cur1 = left;
        int cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
        {
            if ((long long int)nums[cur1] > (long long int)2 * nums[cur2])
            {
                ret += right - cur2 + 1;
                cur1++;
            }
            else cur2++;
        }

        cur1 = left;
        cur2 = mid + 1;
        int i = left;
        while (cur1 <= mid && cur2 <= right)
        {
            //挪左边的比较大的值
            //满足要求就维护ret
            if (nums[cur1] > nums[cur2])
                auxnums[i++] = nums[cur1++];
            else
                auxnums[i++] = nums[cur2++];
        }
        while (cur1 <= mid)
            auxnums[i++] = nums[cur1++];
        while (cur2 <= right)
            auxnums[i++] = nums[cur2++];

        for (int i = left; i <= right; i++)
            nums[i] = auxnums[i];
    }
};


int main()
{
    vector<int> nums = { 1,3,2,3,1 };
    cout << Solution().reversePairs(nums) << endl;
    return 0;
}