#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
// 递归
// class Solution {
// public:
//     int fib(int n) {
//         return __fib(n);
//     }
// private:
//     int __fib(int n) {
//         if (n == 0)
//             return 0;
//         if (n == 1)
//             return 1;
//         return __fib(n - 1) + __fib(n - 2);
//     }
// };

// // 迭代
// class Solution {
// public:
//     int fib(int n) {
//         if (n == 0) return 0;
//         if (n == 1) return 1;
//         vector<int> dp(n + 1, 0);  // 构造时候初始化dp[0]=0
//         dp[1] = 1;

//         for (int i = 2; i <= n; ++ i)
//             dp[i] = dp[i - 1] + dp[i - 2];
//         return dp[n];
//     }

// };


// 迭代，使用san个变量代替数组
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int dp_i_1 = 1, dp_i_2 = 0, dp_i;  // 构造时候初始化dp[0]=0


        for (int i = 2; i <= n; ++i) {
            dp_i = dp_i_1 + dp_i_2;
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }

};

int main() {

	system("pause");
	return 0;
}