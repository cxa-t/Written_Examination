// https://leetcode.cn/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int count = 0;
        //找到正确结束的位置
        int i = 0;
        for (i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
                count += 2;
            else
                count += 1;
            if (count >= arr.size())
                break;
        }
        //这是从后往前写的 下标(指针)
        int j = arr.size() - 1;
        //处理末尾是0的情况
        if (arr[i] == 0 && count > arr.size())
        {
            arr[j--] = 0;
            i--;
        }

        while (i >= 0)
        {
            if (arr[i] == 0)
            {
                arr[j] = arr[j - 1] = 0;
                j -= 2;
            }
            else
            {
                arr[j] = arr[i];
                j -= 1;
            }
            i--;
        }
    }
};
