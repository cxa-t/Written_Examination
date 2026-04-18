// https://leetcode.cn/problems/peak-index-in-a-mountain-array/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int left = 1;
        int right = arr.size() - 2;
        while (left < right)
        {
            // 0 2 4 5 10 9 5
            // l     m  l m r
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};