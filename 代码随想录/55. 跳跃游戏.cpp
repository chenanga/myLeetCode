#include <iostream>
#include <vector>

using namespace std;

/*
��ʵ����������ν���ؼ����ڿ����ĸ��Ƿ�Χ��
��һ����Ҫ��ȷһ�ξ�����������ÿ��ȡ������Ծ������������ǿ�����Ծ�ĸ��Ƿ�Χ��
�����Χ�ڣ��������ô���ģ�����һ��������������
��ô��������ת��Ϊ��Ծ���Ƿ�Χ�����ɲ����Ը��ǵ��յ㣡
ÿ���ƶ�ȡ�����Ծ�������õ����ĸ��Ƿ�Χ����ÿ�ƶ�һ����λ���͸�����󸲸Ƿ�Χ��
̰���㷨�ֲ����Ž⣺ÿ��ȡ�����Ծ������ȡ��󸲸Ƿ�Χ�����������Ž⣺���õ�������󸲸Ƿ�Χ�����Ƿ��ܵ��յ㡣
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i <= index; ++i) {
            index = max(index, i + nums[i]);
            if (index >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main() {

	system("pause");
	return 0;
}