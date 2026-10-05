// https://leetcode.cn/problems/advantage-shuffle/


class Solution // 定义题解类
{
public: // 公有成员区域
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) // 重新排列 nums1，使 nums1[i] > nums2[i] 的位置数量尽可能多，并返回重排后的 nums1
    {
        int n = nums1.size(); // 获取数组长度，nums1 和 nums2 的长度相同
        vector<int> index1(n); // index1 用来保存 nums1 中每个元素的原始下标
        vector<int> index2(n); // index2 用来保存 nums2 中每个元素的原始下标
        for (int i = 0; i < n; i++) index1[i] = i; // 初始化 index1，使每个位置先保存自己的原始下标
        for (int i = 0; i < n; i++) index2[i] = i; // 初始化 index2，使每个位置先保存自己的原始下标
        sort(index1.begin(), index1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; }); // 按照 nums1 中对应元素的大小对下标排序，使 index1 对应的 nums1 元素从小到大排列
        sort(index2.begin(), index2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; }); // 按照 nums2 中对应元素的大小对下标排序，使 index2 对应的 nums2 元素从小到大排列
        vector<int> ret(n); // 创建结果数组，用来保存重新排列后的 nums1
        int left = 0; // left 指向 nums2 当前还没有匹配的最小元素
        int right = n - 1; // right 指向 nums2 当前还没有匹配的最大元素
        for (int i = 0; i < n; i++) // 按照 nums1 从小到大的顺序，依次拿出每一个元素进行匹配
        {
            if (nums1[index1[i]] > nums2[index2[left]]) // 如果 nums1 当前最小的未使用元素能够打赢 nums2 当前最小的未匹配元素
                ret[index2[left++]] = nums1[index1[i]]; // 就用当前 nums1 元素去匹配 nums2 当前最小元素，并把结果放回 nums2 对应的原始位置，同时 left 向右移动
            else // 如果 nums1 当前元素连 nums2 当前最小的元素都无法打赢
                ret[index2[right--]] = nums1[index1[i]]; // 就让当前 nums1 元素去匹配 nums2 当前最大的元素，相当于用较弱元素去“牺牲”，同时 right 向左移动
        }
        return ret; // 返回按照优势最大化策略重新排列后的 nums1
    }
};