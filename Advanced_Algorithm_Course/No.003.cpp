#define _CRT_SECURE_NO_WARNINGS 1

// https://leetcode.cn/problems/happy-number/

class Solution {
public:
    int bitSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int ge = n % 10;
            sum += ge * ge;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int fast = bitSum(n);
        int slow = n;
        while (fast != slow)
        {
            fast = bitSum(bitSum(fast));
            slow = bitSum(slow);
        }
        return slow == 1;
    }
};
