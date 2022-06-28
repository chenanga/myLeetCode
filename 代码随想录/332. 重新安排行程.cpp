#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 所有的机票 必须都用一次 且 只能用一次
        for (const vector<string>& vec : tickets)
            targets[vec[0]][vec[1]] ++;
        vector<string> result;
        result.push_back("JFK");  // 起始机场
        __findItinerary(result, tickets.size());
        return result;

    }
private:
    unordered_map<string, map<string, int>> targets;  // 记录航班的映射关系，xx出发航班对应的目的是睡，有几个
    bool __findItinerary(vector<string>& result, int ticketNum) {
        if (result.size() == ticketNum + 1)
            return true;

        // result[result.size() - 1]访问的是result中的最后一个元素
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {  // 还可以飞
                --target.second;
                result.push_back(target.first);
                if (__findItinerary(result, ticketNum)) return true;
                result.pop_back();
                ++target.second;

            }
        }
        return false;
    }
};

int main() {

	system("pause");
	return 0;
}