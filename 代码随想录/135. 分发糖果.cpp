#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int result = 0;
        vector<int> record(n, 1);  // ��ʼ��=ÿ��һ��

        // һ���Ǵ����ұ�����ֻ�Ƚ��ұߺ������ֱ���ߴ�������
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                record[i] = record[i - 1] + 1;

        }

        // һ���Ǵ��ҵ��������ֻ�Ƚ���ߺ������ֱ��ұߴ�������
        /*
�ֲ����ţ�ȡrecord[i + 1] + 1 �� record[i] �����ǹ���������֤��i��С�����ǹ�������������ߵ�Ҳ�����ұߵġ�
ȫ�����ţ����ڵĺ����У����ָߵĺ��ӻ�ø�����ǹ���
        */
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                record[i] = max(record[i], record[i + 1] + 1);
            result += record[i];
        }
        return result + record[n - 1];
    }
};

int main() {

	system("pause");
	return 0;
}