// https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/?envType=daily-question&envId=2026-11-05


class Solution // 定义题解类，使用排序和二分查找计算两个数组之间的距离值
{
public: // 公有成员区域
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) // 返回 arr1 中与 arr2 所有元素的绝对差都大于 d 的元素数量
    {
        sort(arr2.begin(), arr2.end()); // 先将 arr2 从小到大排序，方便后面使用二分查找
        int ans = 0; // 记录 arr1 中满足条件的元素数量
        for(int i = 0; i < arr1.size(); i++) // 遍历 arr1 中的每一个元素，分别判断是否满足要求
        {
            int x = arr1[i]; // 取出 arr1 中当前需要判断的元素
            int left = x - d; // 计算不符合要求的区间左端点，即 x-d
            int right = x + d; // 计算不符合要求的区间右端点，即 x+d
            vector<int>::iterator it = lower_bound(arr2.begin(), arr2.end(), left); // 使用二分查找，在排好序的 arr2 中寻找第一个大于等于 left 的元素，并返回指向该元素的迭代器
            if(it == arr2.end() || *it > right) // 如果没有找到大于等于 left 的元素，或者找到的第一个元素已经大于 right，说明 arr2 中不存在位于 [left,right] 内的数字
            {
                ans++; // 当前 x 与 arr2 中所有元素的绝对差都大于 d，因此答案加1
            }
        }
        return ans; // 返回 arr1 中所有满足条件的元素数量
    }
};