// https://leetcode.cn/problems/longest-turbulent-subarray/


class Solution
{
public:
    // 计算最长湍流子数组的长度
    int maxTurbulenceSize(vector<int>& arr)
    {
        // n 表示数组长度
        int n = arr.size();
        // 如果数组只有一个元素，最长湍流子数组长度就是 1
        if (n == 1) return 1;
        // f[i] 表示以 arr[i] 结尾，并且最后关系是 arr[i] > arr[i - 1] 的最长湍流长度
        vector<int> f(n, 1);
        // g[i] 表示以 arr[i] 结尾，并且最后关系是 arr[i] < arr[i - 1] 的最长湍流长度
        vector<int> g(n, 1);
        // ret 用来记录最长湍流子数组长度
        int ret = -0x3f3f3f3f;
        // 从下标 1 开始遍历数组
        for (int i = 1; i < n; i++)
        {
            // 如果当前元素大于前一个元素，说明可以接在前一个“小于关系”的状态后面
            if (arr[i] > arr[i - 1]) f[i] = g[i - 1] + 1;
            // 如果当前元素小于前一个元素，说明可以接在前一个“大于关系”的状态后面
            else if (arr[i] < arr[i - 1]) g[i] = f[i - 1] + 1;
            // 更新当前得到的最长湍流子数组长度
            ret = max(ret, max(f[i], g[i]));
        }
        // 返回最长湍流子数组长度
        return ret;
    }
};