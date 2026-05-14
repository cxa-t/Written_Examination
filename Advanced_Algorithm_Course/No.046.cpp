//https://leetcode.cn/problems/smallest-k-lcci/description/

//思路
//就是类似于三路快排划分一样，只不过我们只需要找对个数就可以了
//也就是对别的区间进行划分的时候，我们只需要加上判断条件就可以了
//依据区间的个数选择去哪个区间找
class Solution
{
public:
    vector<int> smallestK(vector<int>& arr, int k)
    {
        srand((unsigned int)time(NULL));
        qselect(arr, 0, arr.size() - 1, k);
        return { arr.begin(),arr.begin() + k };
    }
    void qselect(vector<int>& arr, int left, int right, int k)
    {
        if (left >= right) return;
        int key = getKey(arr, left, right);
        int l = left - 1;
        int i = l + 1;
        int r = right + 1;
        while (i < r)
        {
            if (arr[i] < key) swap(arr[++l], arr[i++]);
            else if (arr[i] > key) swap(arr[--r], arr[i]);
            else i++;
        }
        int a = l - left + 1;
        int b = (r - 1) - (l + 1) + 1;
        int c = right - r + 1;
        if (a > k) qselect(arr, left, l, k);
        else if (a + b >= k) return;
        else qselect(arr, r, right, k - a - b);
    }
    int getKey(vector<int>& arr, int left, int right)
    {
        int pos = rand() % (right - left + 1) + left;
        return arr[pos];
    }

};