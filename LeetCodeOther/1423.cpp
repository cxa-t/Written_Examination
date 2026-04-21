// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int>& arr, int k)
    {
        int n = arr.size();
        int nt = n - k;

        int sumarr = 0;
        for (auto e : arr) sumarr += e;

        int left = 0;
        int right = 0;
        int ret = INT_MAX;
        int sum = 0;
        while (right < n)
        {
            sum += arr[right];
            if (right - left + 1 > nt) sum -= arr[left++];
            if(right - left + 1 == nt) ret = min(ret, sum);
            right++;
        }
        return sumarr - ret;
    }
};

int main()
{
    Solution su;
    vector<int> arr = { 1,2,3,4,5,6,1 };
    int k = 3;
    su.maxScore(arr, k);
    return 0;
}