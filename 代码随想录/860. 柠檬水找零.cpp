#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         unordered_map<int, int> record; //��¼��ͬ����Ǯ��Ӧ������

//         for (int i = 0; i < bills.size(); ++ i) {
//             if (bills[i] == 5)
//                 record[5] ++;
//             else if (bills[i] == 10) {
//                 if (record[5] == 0)
//                     return false;
//                 record[5] --;
//                 record[10] ++;
//             }
//             else { // bills[i] == 20
//                 if (record[5] == 0)
//                     return false;

//                 //�ȳ�����һ��10��һ��5
//                 if (record[10] != 0) {
//                     record[10] --;
//                     record[5] --;
//                     record[20] ++;
//                 }
//                 else { //record[10] == 0
//                     //�ڳ�����3��5
//                     if (record[5] >= 3) {
//                         record[5] -= 3;
//                         record[20] ++;
//                     }
//                     else 
//                         return false;
//                 }


//             }
//         }
//         return true;
//     }
// };
/*
                // cout << "bills[" << i <<"] = " << bills[i] << ",record[5] = " << record[5] << endl;
                // cout << "record.count(5) = " << record.count(5) << endl;

*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; //20�Ĳ��ü�¼���ò���

        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else { // bills[i] == 20
                if (five == 0) //һ��5Ԫ��û�У��϶��޷����㣬ֱ��return
                    return false;

                //�ȳ�����һ��10��һ��5
                if (ten != 0) {
                    ten--;
                    five--;
                }
                else { //record[10] == 0
                    //�ڳ�����3��5
                    if (five >= 3)
                        five -= 3;
                    else
                        return false;
                }

            }
        }
        return true;
    }
};

int main() {

	system("pause");
	return 0;
}