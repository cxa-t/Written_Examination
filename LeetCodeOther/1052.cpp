// https://leetcode.cn/problems/grumpy-bookstore-owner/

class Solution
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int left = 0;
        int right = 0;
        int max_cust = 0;
        int s[2] = { 0 };
        //s[0]只记录本来就满意的顾客数量
        //s[1]记录的是当前窗口内不满意的顾客数量
        while (right < customers.size())
        {
            //首先统计当前位置的不满意或满意的顾客数量
            s[grumpy[right]] += customers[right];
            //如果数量超了，我们只需要管最左元素是不是不满意的顾客，是的话维护s[1]
            if (right - left + 1 > minutes)
            {
                if (grumpy[left] == 1) s[1] -= customers[left];
                left++;
            }
            //维护完后，当前位置也进窗口了，左边元素也出窗口了，直接更新最大的结果
            //也就是每个窗口中最大的不满意顾客数量
            max_cust = max(s[1], max_cust);
            right++;
        }
        //s[0]只记录本来就满意的顾客数，也没有修改啥的，所以直接用，而维护的max_cust是最大的不满意客户数，直接加就可
        return s[0] + max_cust;
    }
};