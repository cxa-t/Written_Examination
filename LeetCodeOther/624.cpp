//

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        //思路：
        //把二维vector内部的vector，当作一个整体，这样就简化成之前做过的思路
        //只需考虑每个数组的最小值和最大值。题目保证数组升序
        //所以数组第一个数就是最小值，最后一个数就是最大值
        //只需要更新两个最大最小之间差和之前结果的大小
        //这里怎么保证选的数在不同的数组呢？
        //每次计算的ret都是以现在这个数组 和之前所有数组的极值计算的，所以一定不在一个数组
        int ret = 0;
        int minl = INT_MAX / 2;
        int maxl = INT_MIN / 2;
        for (auto& a : arrays)
        {
            ret = max({ ret, maxl - a[0], a.back() - minl });
            minl = min(minl, a[0]);
            maxl = max(maxl, a.back());
        }
        return ret;
    }
};
int main()
{
    vector<vector<int>> arrays = { {1},{1} };
    Solution().maxDistance(arrays);
    return 0;
}