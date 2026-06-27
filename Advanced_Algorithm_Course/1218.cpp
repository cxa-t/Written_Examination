// https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/


class Solution
{
public:
    // 计算差值为 difference 的最长等差子序列长度
    int longestSubsequence(vector<int>& arr, int difference)
    {
        // hash[x] 表示以数字 x 结尾的最长等差子序列长度
        unordered_map<int, int> hash;
        // 初始化第一个数字结尾的最长长度为 1
        hash[arr[0]] = 1;
        // ret 用来记录全局最长等差子序列长度
        int ret = 1;
        // 从第 2 个元素开始遍历数组
        for (int i = 1; i < arr.size(); i++)
        {
            // 如果当前数是 arr[i]，那么它前一个数应该是 arr[i] - difference
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            // 更新最长等差子序列长度
            ret = max(ret, hash[arr[i]]);
        }
        // 返回最长等差子序列长度
        return ret;
    }
};