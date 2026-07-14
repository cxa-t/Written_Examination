// https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked


class Solution
{
public:
    // 计算数组中最长连续序列的长度
    int longestConsecutive(vector<int>& nums)
    {
        // ret 用来记录最长连续序列长度
        int ret = 0;
        // 将 nums 中的所有元素放入哈希集合，方便 O(1) 查找，并自动去重
        unordered_set<int> hash(nums.begin(), nums.end());

        // 遍历哈希集合中的每一个数字
        for (auto& e : hash)
        {
            // 如果 e - 1 存在，说明 e 不是连续序列的起点，直接跳过
            if (hash.count(e - 1)) continue;
            // len 表示以当前数字 e 为起点的连续序列长度
            int len = 1;
            // cur 表示当前连续序列走到的数字
            int cur = e;
            // 只要 cur + 1 存在，说明连续序列还能继续
            while (hash.count(cur + 1))
            {
                // cur 向后移动到下一个连续数字
                cur++;
                // 连续序列长度加 1
                len++;
            }
            // 更新最长连续序列长度
            ret = max(ret, len);
        }
        // 返回最长连续序列长度
        return ret;
    }
};