// https://leetcode.cn/problems/russian-doll-envelopes/


class Solution 
{
public: 
    int maxEnvelopes(vector<vector<int>>& e) // 返回最多可以嵌套多少个信封，要求内层信封的宽和高都严格小于外层信封
    {
        sort(e.begin(), e.end(), // 对所有信封进行排序，为后面的二维问题转换成一维 LIS 做准备
             [&](const vector<int>& v1, const vector<int>& v2) -> bool { // 定义排序规则，比较两个信封 v1 和 v2
                 return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] > v2[1]; // 宽度不同时按宽度升序，宽度相同时按高度降序排列
             }); // 排序结束；宽度相同的信封高度必须降序，这样可以避免它们在 LIS 中被错误地同时选中
        vector<int> ret; // ret 用来维护当前能够形成的最长递增子序列的“最小结尾高度”
        ret.push_back(e[0][1]); // 先把第一个信封的高度加入 ret，作为初始的 LIS 结尾
        for (int i = 1; i < e.size(); i++) // 从第二个信封开始依次处理所有信封
        {
            int b = e[i][1]; // 取出当前信封的高度，因为宽度已经按照升序排列，所以现在只需要处理高度
            if (b > ret.back()) // 如果当前高度大于 ret 中最后一个高度，说明可以将当前高度接到最长递增子序列后面
            {
                ret.push_back(b); // 将当前高度加入 ret，使当前能够形成的递增序列长度加1
            }
            else // 如果当前高度小于等于 ret.back()，说明不能直接扩展 LIS，需要寻找合适的位置替换
            {
                int left = 0, right = ret.size() - 1; // 使用二分查找寻找 ret 中第一个大于等于 b 的位置
                while (left < right) // 当搜索区间中还存在多个位置时继续二分查找
                {
                    int mid = (left + right) / 2; // 计算当前搜索区间的中间位置
                    if (ret[mid] >= b) // 如果中间位置的高度大于等于当前高度，说明答案可能在 mid 或 mid 的左边
                        right = mid; // 将右边界移动到 mid，继续寻找第一个大于等于 b 的位置
                    else // 如果 ret[mid] 小于当前高度
                        left = mid + 1; // 说明 mid 以及左边的位置都不符合要求，答案一定在右侧
                }
                ret[left] = b; // 用当前更小的高度替换第一个大于等于 b 的位置，使相同长度的递增序列拥有更小的结尾，更有利于后续扩展
            }
        }
        return ret.size(); // ret 的长度就是最长严格递增子序列的长度，也就是最多可以嵌套的信封数量
    }
};
