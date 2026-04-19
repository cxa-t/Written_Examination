//https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/

class Solution
{
public:
    int takeAttendance(vector<int>& records)
    {
        int left = 0;
        int right = records.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid) left = mid + 1;
            else right = mid;
        }
        return records[left] == left ? left + 1 : left;
        //return left + 1; 
    }
};