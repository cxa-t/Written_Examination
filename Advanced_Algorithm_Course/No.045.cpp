//https://leetcode.cn/problems/kth-largest-element-in-an-array/

//思路
//就是类似于三路快排划分一样，只不过我们只需要找到数就可以了
//也就是对别的区间进行划分的时候，我们只需要加上判断条件就可以了
//依据区间的个数选择去哪个区间找
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        srand((unsigned int)time(NULL));
        return Find(nums, 0, nums.size() - 1, k);
    }

    int Find(vector<int>& nums, int left, int right, int k)
    {
        if (left >= right) return nums[left];
        int key = GetKey(nums, left, right);
        int l = left - 1;
        int i = l + 1;
        int r = right + 1;
        while (i < r)
        {
            if (nums[i] < key) swap(nums[++l], nums[i++]);
            else if (nums[i] > key) swap(nums[--r], nums[i]);
            else i++;
        }
        //
        int c = right - r + 1;
        int b = (r - 1) - (l + 1) + 1;
        if (c >= k) return Find(nums, r, right, k);
        else if (b + c >= k) return key;
        else return Find(nums, left, l, k - b - c);
    }

    int GetKey(vector<int>& nums, int left, int right)
    {
        int pos = rand() % (right - left + 1) + left;
        return nums[pos];
    }
};