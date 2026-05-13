//https://leetcode.cn/problems/sort-an-array/description/

//思路：
//其实就是三路快排
//每次处理区间的时候，将所有相同的元素放在当前区间的一块地放
//假设你传进去的是[left, right]
//这时候你要进行将数组划分为三个区间，就需要自己再定义边界，便于后续操作
//按照75题分颜色的基础，定义区间为[l, left, right, r]
//处理完后一定是[left, l, r, right]，这里的lr跟原始传入的左右相不相等不管
//那么当前区间剩下的没处理的就是[left, l] 和 [r, right]
class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        srand((unsigned int)time(NULL));
        Sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void Sort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int key = GetKey(nums, left, right);
        int l = left - 1;
        int i = l + 1;
        int r = right + 1;
        while (i < r)
        {
            if (nums[i] > key) swap(nums[--r], nums[i]);
            else if (nums[i] < key) swap(nums[++l], nums[i++]);
            else i++;
        }
        //[left, right]
        //[ l, left, right, r ]
        //[left, l, r, right]
        //[0,left] [left+1,i-1] [i,right-1] [right,n-1]
        Sort(nums, left, l);
        Sort(nums, r, right);
    }
    //这里可以不需要写上面，因为在类域查找是全域查找，而不是一直往上找
    int GetKey(vector<int>& nums, int left, int right)
    {
        int pos = rand() % (right - left + 1) + left;
        return nums[pos];
    }
};