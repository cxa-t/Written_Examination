//https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?tpId=230&tqId=2032575&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196

#include <iostream>                                              // 引入标准输入输出库
#include <vector>                                                // 引入动态数组容器
#include <algorithm>                                             // 引入max等算法函数
int main()                                                       // 程序入口函数
{
    int n = 0;                                                   // 保存物品数量
    int V = 0;                                                   // 保存背包容量
    std::cin >> n >> V;                                          // 输入物品数量和背包容量
    std::vector<int> v(n);                                       // 保存每个物品的体积
    std::vector<int> w(n);                                       // 保存每个物品的价值
    for (int i = 0; i < n; i++) std::cin >> v[i] >> w[i];         // 输入每个物品的体积和价值
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(V + 1)); // dp[i][j]表示前i种物品在容量j下的最大价值
    for (int i = 1; i <= n; i++)                                  // 依次考虑每一种物品
    {
        for (int j = 0; j <= V; j++)                              // 枚举当前背包容量
        {
            dp[i][j] = dp[i - 1][j];                             // 不选择第i种物品时继承上一层结果
            if (j >= v[i - 1])                                    // 当前容量能够放下第i种物品
                dp[i][j] = std::max(dp[i][j], dp[i][j - v[i - 1]] + w[i - 1]); // 选择当前物品并允许重复使用
        }
    }
    std::cout << dp[n][V] << std::endl;                           // 输出容量不超过V时的最大价值
    dp.resize(n + 1, std::vector<int>(V + 1));                    // 重新初始化dp用于恰好装满背包的问题
    for (int j = 1; j <= V; j++) dp[0][j] = -1;                   // 没有物品时无法恰好凑出正容量
    for (int i = 1; i <= n; i++)                                  // 依次考虑每一种物品
    {
        for (int j = 0; j <= V; j++)                              // 枚举当前需要恰好凑出的容量
        {
            dp[i][j] = dp[i - 1][j];                             // 不选择第i种物品时继承上一层状态
            if (j >= v[i - 1] && dp[i][j - v[i - 1]] != -1)      // 剩余容量可达时才能继续选择当前物品
                dp[i][j] = std::max(dp[i][j], dp[i][j - v[i - 1]] + w[i - 1]); // 重复选择当前物品并更新最大价值
        }
    }
    std::cout << (dp[n][V] == -1 ? 0 : dp[n][V]);                // 无法恰好装满时输出0否则输出最大价值
    return 0;                                                    // 程序正常结束
}