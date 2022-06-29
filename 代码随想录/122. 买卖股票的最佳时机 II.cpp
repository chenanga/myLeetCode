#include <iostream>
#include <vector>

using namespace std;

// // 贪心让每次卖出的尽可能多
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() == 1) return 0;
//         if (prices.size() == 2) return max(0, prices[1] - prices[0]);


//         // preDiff代表上次卖出能赚的钱
//         int preDiff = prices[1] - prices[0], result = 0;

//         for (int i = 2; i < prices.size(); ++ i) {

//             // 如果上次卖出能赚的钱是正的，并且当前比上一次价格更高，那么在今天卖，还能赚的更多，更新preDiff
//             if (preDiff > 0 && prices[i] > prices[i - 1]) {
//                 preDiff += (prices[i] - prices[i - 1]);
//                 if (i == prices.size() - 1)  // 如果有每天都是递增的价格，则result没用被更新，这个地方加个判断
//                     result += preDiff;
//             }

//             // 如果上次卖出赚的钱是正 的，但是今天价格比昨天低，那么就认为昨天卖出，更新result
//             else if (preDiff > 0 && prices[i] <= prices[i - 1]) {
//                 result += preDiff;
//                 preDiff = prices[i] - prices[i - 1];
//             }

//             //
//             else {  // preDiff <= 0
//                 preDiff = prices[i] - prices[i - 1];
//                 if (i == prices.size() - 1 && preDiff > 0)  //如果刚好最后一次是挣钱，那么加入result 
//                     result += preDiff;
//             }


//         }
//         return result;
//     }
// };


// 贪心2，分隔一个一个的小区间，收集正的利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int result = 0;

        for (int i = 1; i < prices.size(); ++i) {

            if (prices[i] - prices[i - 1] > 0)
                result += prices[i] - prices[i - 1];
        }

        return result;
    }
};

int main() {

	system("pause");
	return 0;
}