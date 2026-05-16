//https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

#include<iostream>
#include<vector>
using namespace std;

//思路:
//在归并一小块内容的时候 如果排升序的时候，则重点关注后半块内容
//后板块内容往前排的时候，表示当前前面的部分都比它大，也就都是逆序，直接维护总数就可以
class Solution {
public:
    vector<int> tmp;
    int reversePairs(vector<int>& record)
    {
        tmp.resize(record.size());
        int ret = 0;
        mergesort(record, 0, record.size() - 1, ret);
        return ret;
    }
    void mergesort(vector<int>& record, int left, int right, int& ret)
    {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        mergesort(record, left, mid, ret);
        mergesort(record, mid + 1, right, ret);
        int cur1 = left;
        int cur2 = mid + 1;
        int i = left;
        while (cur1 <= mid && cur2 <= right)
        {
            if (record[cur2] < record[cur1])
            {
                tmp[i++] = record[cur2++];
                ret += (mid - cur1 + 1);
            }
            else tmp[i++] = record[cur1++];
        }
        while (cur1 <= mid) tmp[i++] = record[cur1++];
        while (cur2 <= right) tmp[i++] = record[cur2++];
        for (int i = left; i <= right; i++) record[i] = tmp[i];
    }
};

int main()
{
    vector<int> record = { 1,3,2,3,1 };
    Solution().reversePairs(record);
    return 0;
}