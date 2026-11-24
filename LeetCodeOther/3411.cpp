// https://leetcode.cn/problems/maximum-subarray-with-equal-products/?envType=daily-question&envId=2026-11-24

class Solution 
{
public:
    int maxLength(vector<int>& nums) 
    {
        // int maxlen = 0;                       // 记录满足条件的最长连续子数组长度
        // for(int i = 0; i < nums.size(); i++)  // 枚举连续子数组的起始位置
        // {
        //     int proc = nums[i];               // 初始化当前子数组的乘积
        //     int glcd = nums[i];               // 初始化当前子数组的最大公约数
        //     int glcm = nums[i];               // 初始化当前子数组的最小公倍数
        //     for(int j = i + 1; j < nums.size(); j++) // 枚举当前起点之后的结束位置
        //     {
        //         proc *= nums[j];              // 将新元素加入子数组，更新乘积
        //         glcd = gcd(glcd, nums[j]);    // 更新当前子数组的最大公约数
        //         glcm = lcm(glcm, nums[j]);    // 更新当前子数组的最小公倍数
        //         if(proc == glcd * glcm)       // 判断乘积是否等于最大公约数乘最小公倍数
        //             maxlen = max(maxlen, j - i + 1); // 满足条件，更新最长子数组长度
        //         else break;                   // 不满足条件，结束当前起点的枚举
        //     }
        // }
        // return maxlen;                        // 返回满足条件的最长连续子数组长度

        int ret = 2;                            // 初始化答案为2，因为任意两个正整数都满足条件
        int left = 0;                           // 定义滑动窗口左边界
        int mul = 1;                            // 维护当前窗口内所有元素的乘积

        for(int right = 0; right < nums.size(); right++) // right向右扩展窗口
        {
            while(gcd(mul, nums[right]) > 1)   // 如果新元素与窗口乘积不互质，说明存在公因数
            {
                mul /= nums[left];             // 移除窗口最左侧元素，更新窗口乘积
                left++;                        // 左边界右移，缩小窗口
            }
            mul *= nums[right];                // 将当前元素加入窗口，更新乘积
            ret = max(ret, right - left + 1);  // 更新最长合法连续子数组长度
        }
        return ret;                            // 返回最长合法连续子数组长度
    }
};