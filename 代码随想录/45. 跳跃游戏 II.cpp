#include <iostream>
#include <vector>

using namespace std;

/*
������Ҫͳ���������Ƿ�Χ����ǰ��һ������󸲸Ǻ���һ����󸲸ǡ�

����ƶ��±�ﵽ�˵�ǰ��һ������󸲸���Զ�����ˣ���û�е��յ�Ļ�����ô�ͱ�������һ�������Ӹ��Ƿ�Χ��ֱ�����Ƿ�Χ�������յ㡣
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0, nextDistance = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {

            nextDistance = max(nextDistance, i + nums[i]);

            // �ﵽ�˵�ǰ��һ������󸲸���Զ�����ˣ���û�е��յ�
            if (i >= curDistance && i < nums.size() - 1) {
                count++;
                curDistance = nextDistance;

                // ��֦�����ĳһ��ʱ���´ο��Ե��յ㣬��ôֱ��return
                if (nextDistance >= nums.size() - 1)
                    return count;
            }
            else if (i >= curDistance && i == nums.size() - 1) // �ﵽ�˵�ǰ��һ������󸲸���Զ�����ˣ��ҵ����յ�
                return count;
        }
        return count;
    }
};

int main() {

	system("pause");
	return 0;
}