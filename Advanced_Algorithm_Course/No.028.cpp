// https://leetcode.cn/problems/product-of-array-except-self/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        //计算前缀积和后缀积
        int n = nums.size();
        vector<int> leftMul(n, 1);
        vector<int> rightMul(n, 1);
        for (int i = 1; i < n; i++)
        {
            leftMul[i] = leftMul[i - 1] * nums[i - 1];
            //cout<< leftMul[i]<<" ";
        }
        //cout<<endl;
        for (int i = n - 2; i >= 0; i--)
        {
            rightMul[i] = rightMul[i + 1] * nums[i + 1];
            //cout<< rightMul[i]<< " ";
        }
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = leftMul[i] * rightMul[i];
        }
        return ret;
    }
};

int main()
{
    Solution su;
    vector<int> nums = { 1,2,3,4 };
    su.productExceptSelf(nums);
    return 0;
}