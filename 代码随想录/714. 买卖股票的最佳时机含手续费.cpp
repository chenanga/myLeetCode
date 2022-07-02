#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            // 更新最低价格
            if (prices[i] < minPrice) minPrice = prices[i];

            // if (prices[i] - minPrice <= fee)  // 可以省略
            //     continue; 
            if (prices[i] > minPrice + fee) {
                result += (prices[i] - minPrice - fee);
                minPrice = prices[i] - fee;  // 不是真的卖出
                /*
                我们此时卖出股票可能并不是全局最优的（例如下一天股票价格继续上升），
                因此我们可以提供一个反悔操作，看成当前手上拥有一支买入价格为 prices[i] 的股票
                如果下一天股票继续上升，那么赚的钱是prices[i+1] - minprices, 此时由于手续费被提前减掉               了，相当于两天合在一起交易的


                */
            }
        }
        return result;
    }
};

int main() {

	system("pause");
	return 0;
}