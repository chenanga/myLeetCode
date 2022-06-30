#include <iostream>
#include <vector>
using namespace std;

// 34 / 37 ��ͨ����������
// ������ʱ
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         for (int i = 0; i < n; ++ i) {
//             int rest = gas[i] - cost[i], index =  (i + 1) % n;
//             // �п��ܵ�һ�ε�rest��С��0����ô�Ͳ��ܽ�ȥwhileѭ��
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

// // ȫ������
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         // ����㿪ʼ�ۼ�gas[i]-cost[i]��
//         // ��������ۼ�ֵС��0��˵�����ܴ���������������㣬return -1
//         // ����ۼӹ����е���Сֵ���ڵ���0��˵����0��ʼ��������
//         // �Ӻ���ǰ������ʲôʱ���ܰѸ���������
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

//         return -1;  // һ�㲻�ᵽ��һ��

//     }
// };

// ̰��
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // ����㿪ʼ�ۼ�gas[i]-cost[i]��
        // �����ǰ�ۼ�ֵС��0������startλ��
        int sum = 0, cursum = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            cursum += (gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
            if (cursum < 0) {
                cursum = 0;
                start = i + 1;
            }
        }
        if (sum < 0) return -1;  // ������ζ��߲���һȦ

        return start;  // һ�㲻�ᵽ��һ��   
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