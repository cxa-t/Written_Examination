// https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/

class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) // 对数组中的元素恰好进行 k 次取反操作，返回能够得到的最大数组和
    {
        int count = 0; // 记录数组中负数的个数
        int minnum = INT_MAX; // 记录数组中绝对值最小的元素
        for (int& e : nums) // 遍历数组中的每一个元素
        {
            if (e < 0) count++; // 如果当前元素是负数，则负数个数加1
            minnum = min(minnum, abs(e)); // 更新绝对值最小的元素，后面可能需要将它额外取反
        }
        int ret = 0; // 记录经过 k 次取反操作后能够得到的最大数组和
        if (count > k) // 如果负数个数大于 k，说明无法把所有负数都变成正数
        {
            sort(nums.begin(), nums.end()); // 将数组从小到大排序，使数值最小、绝对值较大的负数排在前面
            for (int i = 0; i < k; i++) ret += abs(nums[i]); // 将前 k 个负数取反，相当于把它们变成正数后加入结果
            for (int i = k; i < nums.size(); i++) ret += nums[i]; // 剩余元素不再进行取反，直接累加到结果中
        }
        else // 如果负数个数小于等于 k，说明可以先把所有负数都变成正数
        {
            for (int& e : nums) ret += abs(e); // 先将所有元素都按照正数形式累加，相当于把所有负数都取反
            if ((k - count) % 2 == 1) ret -= minnum * 2; // 如果处理完所有负数后还剩奇数次操作，就必须让绝对值最小的元素最终变为负数，因此总和减少 2*minnum
        }
        return ret; // 返回经过 k 次取反后能够得到的最大数组和
    }
};