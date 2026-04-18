// https://leetcode.cn/problems/sqrtx/

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 1) return 0;
        int left = 1;
        int right = x;
        while (left < right)
        {
            long long int mid = left + (right - left + 1) / 2;
            // 8
            // 2 3
            // l r
            // 需要一直往左靠找到 l平方小于x的数
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};