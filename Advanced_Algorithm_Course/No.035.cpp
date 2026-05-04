//https://leetcode.cn/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int x = a ^ b;//无进位相加的结果
            size_t carry = (size_t)((a & b) << 1);//计算出进位然后左移再进行无进位相加
            a = x;
            b = carry;
        }
        return a;
    }
};