// https://leetcode.cn/problems/simplify-path/


class Solution
{
public:
    // 简化 Unix 风格的绝对路径
    string simplifyPath(string path)
    {
        // 用 vector 模拟栈，保存有效目录名
        vector<string> stk;
        // n 表示路径字符串长度
        int n = path.size();
        // i 用来遍历路径字符串
        int i = 0;
        // 从左到右扫描整个路径
        while (i < n)
        {
            // 跳过连续的 '/'，避免把空目录加入栈中
            while (i < n && path[i] == '/') i++;
            // 如果已经遍历完字符串，直接退出循环
            if (i >= n) break;
            // j 用来寻找当前目录名的结束位置
            int j = i;
            // 从当前位置开始，找到下一个 '/' 或字符串结尾
            while (j < n && path[j] != '/') j++;
            // 截取当前目录名
            string name = path.substr(i, j - i);
            // 如果当前目录名是 ".."，表示返回上一级目录
            if (name == "..")
            {
                // 如果栈不为空，就弹出上一级目录
                if (!stk.empty())
                    stk.pop_back();
            }
            // 如果当前目录名是 "."，表示当前目录，直接忽略
            else if (name == ".") {}
            // 如果是普通目录名，就加入栈中
            else stk.push_back(name);
            // 从当前目录名结束的位置继续往后遍历
            i = j;
        }
        // 如果栈为空，说明最终路径是根目录
        if (stk.empty()) return "/";
        // ret 用来拼接最终简化后的路径
        string ret;
        // 依次取出栈中的目录名并拼接路径
        for (string& s : stk)
        {
            // 每一级目录前面都要加 '/'
            ret += "/";
            // 拼接当前目录名
            ret += s;
        }
        // 返回最终简化后的路径
        return ret;
    }
};