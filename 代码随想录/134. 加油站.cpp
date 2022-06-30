#include <iostream>
#include <vector>
using namespace std;

// 34 / 37 个通过测试用例
// 暴力超时
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         for (int i = 0; i < n; ++ i) {
//             int rest = gas[i] - cost[i], index =  (i + 1) % n;
//             // 有可能第一次的rest就小于0，那么就不能进去while循环
//             while (rest >= 0 && index != i) {
//                 rest += gas[index] - cost[index];
//                 index = (index + 1) % n;
//             }
//             if (rest >=0 && index == i) 
//                 return i;
//         }
//         return -1;
//     }
// };

// // 全局最优
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         // 从起点开始累加gas[i]-cost[i]，
//         // 如果最终累加值小于0，说明不管从哪里出发都不满足，return -1
//         // 如果累加过程中的最小值大于等于0，说明从0开始满足题意
//         // 从后往前，看看什么时候能把负数抵消，
//         int sum = 0, minSum = INT_MAX;
//         for (int i = 0; i < n; ++ i) {
//             sum += (gas[i] - cost[i]);
//             if (sum < minSum)
//                 minSum = sum;
//         }
//         if (sum < 0) return -1;
//         if (minSum >= 0) return 0;

//         for (int i = n - 1; i >= 0; -- i) {
//             minSum += (gas[i] - cost[i]);
//             if (minSum >= 0)
//                 return i;
//         }

//         return -1;  // 一般不会到这一步

//     }
// };

// 贪心
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // 从起点开始累加gas[i]-cost[i]，
        // 如果当前累加值小于0，更新start位置
        int sum = 0, cursum = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            cursum += (gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
            if (cursum < 0) {
                cursum = 0;
                start = i + 1;
            }
        }
        if (sum < 0) return -1;  // 无论如何都走不完一圈

        return start;  // 一般不会到这一步   
    }
};


int main() {

	vector<int>vec1, vec2;
	int tempNum;
	while (cin >> tempNum) {
		vec1.push_back(tempNum);
		char ch = getchar();
		if (ch == '\n')
			break;
	}
	while (cin >> tempNum) {
		vec2.push_back(tempNum);
		char ch = getchar();
		if (ch == '\n')
			break;
	}

	cout << Solution().canCompleteCircuit(vec1, vec2) << endl;

	system("pause");
	return 0;
}