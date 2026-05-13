//https://leetcode.cn/problems/sort-colors/

//思路
//使用三指针将数组划分为三个区间（实际在划分中是四个区间，划分结束是三个）
//    i
//   [                         ]
//left                          right
//划分过程中的四个区间
//[0,left]     应该全是0
//[left+1,i-1] 应该全是1
//[i,right-1]  应该全是不确定的
//[right,n-1]  应该全是2
//所以在i扫描的时候，遇到0和1 跟左边交换，往后走
//遇到2，跟右边交换，但是由于右边这个元素在第三个区间，属于没有划分的，所以不能往后走

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int left = -1;
        int right = n;
        int i = 0;
        while (i < right)
        {
            if (nums[i] == 0) swap(nums[++left], nums[i++]);
            else if (nums[i] == 2) swap(nums[--right], nums[i]);
            else i++;
        }
    }
};