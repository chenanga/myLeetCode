#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;  // ���ÿ�εĴ�
        __findSubsequences(nums, path, 0);
        return result;
    }
private:
    vector<vector<int>> result;   // ������յĴ�
    void __findSubsequences(vector<int>& nums, vector<int>& path, int start) {

        // ��֤����Ϊ2������
        if (path.size() >= 2)
            result.push_back(path);

        // �ݹ���ֹ����
        if (start == nums.size())
            return;

        vector<int> used(201, false);
        for (int i = start; i < nums.size(); ++i) {
            if (used[nums[i] + 100]) // �����ǰλ�õ�Ԫ��ֵ�Ѿ�ʹ�ù����������һ��ѭ������������
                continue;
            if (path.empty()) { // ���pathΪ�գ���ֱ�Ӳ��뵱ǰԪ��
                used[nums[i] + 100] = true;
                path.push_back(nums[i]);
                __findSubsequences(nums, path, i + 1);
                path.pop_back();
            }
            else { // path��Ϊ��
                if (nums[i] >= path.back()) {  // �жϵ�ǰԪ���Ƿ���ڵ���path �����һ��Ԫ��
                    used[nums[i] + 100] = true;
                    path.push_back(nums[i]);
                    __findSubsequences(nums, path, i + 1);
                    path.pop_back();
                }
            }
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}