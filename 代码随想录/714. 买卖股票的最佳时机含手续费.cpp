#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            // ������ͼ۸�
            if (prices[i] < minPrice) minPrice = prices[i];

            // if (prices[i] - minPrice <= fee)  // ����ʡ��
            //     continue; 
            if (prices[i] > minPrice + fee) {
                result += (prices[i] - minPrice - fee);
                minPrice = prices[i] - fee;  // �����������
                /*
                ���Ǵ�ʱ������Ʊ���ܲ�����ȫ�����ŵģ�������һ���Ʊ�۸������������
                ������ǿ����ṩһ�����ڲ��������ɵ�ǰ����ӵ��һ֧����۸�Ϊ prices[i] �Ĺ�Ʊ
                �����һ���Ʊ������������ô׬��Ǯ��prices[i+1] - minprices, ��ʱ���������ѱ���ǰ����               �ˣ��൱���������һ���׵�


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