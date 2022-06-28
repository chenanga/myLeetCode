#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // ���еĻ�Ʊ ���붼��һ�� �� ֻ����һ��
        for (const vector<string>& vec : tickets)
            targets[vec[0]][vec[1]] ++;
        vector<string> result;
        result.push_back("JFK");  // ��ʼ����
        __findItinerary(result, tickets.size());
        return result;

    }
private:
    unordered_map<string, map<string, int>> targets;  // ��¼�����ӳ���ϵ��xx���������Ӧ��Ŀ����˯���м���
    bool __findItinerary(vector<string>& result, int ticketNum) {
        if (result.size() == ticketNum + 1)
            return true;

        // result[result.size() - 1]���ʵ���result�е����һ��Ԫ��
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {  // �����Է�
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