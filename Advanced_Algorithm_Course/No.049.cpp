// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/


//思路：
//需要将原始数组和原始数组的下标先进行统一存放起来
//因为你排序的时候会不停挪数据，所以下标一定会乱，但是你必须对同一个元素进行计数
//所以需要将元素和下标进行绑定，此时你index的数组里面的元素就是被绑定的下标
class Solution
{
    vector<int> tmpnum;//归并时的辅助元素数组
    vector<int> tmpindex;//归并时的辅助下标数组
    vector<int> index;//记录下标
    vector<int> ret;//记录答案
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        tmpnum.resize(nums.size());
        tmpindex.resize(nums.size());
        ret.resize(nums.size());
        index.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
            index[i] = i;
        mergesort(nums, 0, nums.size() - 1);
        return ret;
    }
    //升序
    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        int cur1 = left;
        int cur2 = mid + 1;
        int i = left;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur2] >= nums[cur1])//右边大或者等直接挪下来，免的左边多加一次
            {
                tmpnum[i] = nums[cur2];
                tmpindex[i++] = index[cur2++];
            }
            else
            {
                ret[index[cur1]] += right - cur2 + 1;
                tmpnum[i] = nums[cur1];
                tmpindex[i++] = index[cur1++];
            }
        }
        while (cur1 <= mid)
        {
            tmpnum[i] = nums[cur1];
            tmpindex[i++] = index[cur1++];
        }
        while (cur2 <= right)
        {
            tmpnum[i] = nums[cur2];
            tmpindex[i++] = index[cur2++];
        }
        for (int i = left; i <= right; i++)
        {
            nums[i] = tmpnum[i];
            index[i] = tmpindex[i];
        }
    }
};