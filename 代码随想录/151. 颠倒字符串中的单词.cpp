#include "general.h"

// class Solution {
// public:
//     string reverseWords(string s) {
//         string res;
//         int i = s.size() - 1;
//         while (i >= 0) {
//             while (i >= 0 && s[i] == ' ')
//                 -- i;
//             if (i <= -1) break;
//             int end = i;
//             while (i >= 0 && s[i] != ' ')
//                 -- i;

//             string temp =  s.substr(i + 1, end - i);
//             res += temp + " ";


//         }
//         res.pop_back();
//         return res;
//     }
// };


class Solution {
public:
	string reverseWords(string s) {
		removeExtraSpaces(s);

		int left = 0, right = s.size() - 1;
		while (left < right)
			swap(s[left++], s[right--]);

		left = 0;
		for (int i = 0; i <= s.size(); ++i) {
			if (s[i] == ' ' || s.size() == i) {
				reverseStr(s, left, i - 1);
				left = i + 1;
			}
		}

		return s;
	}
private:
	void removeExtraSpaces(string& s) {
		int slow = 0, fast = 0;
		while (fast < s.size()) {
			if (s[fast] != ' ') {
				if (slow != 0)
					s[slow++] = ' ';  // 加空格
				while (fast < s.size() && s[fast] != ' ')
					s[slow++] = s[fast++];
			}
			else
				++fast;
		}
		s.resize(slow);
		return;
	}
	// 反转指定区间的 s[left...right]
	void reverseStr(string& s, int left, int right) {
		while (left < right)
			swap(s[left++], s[right--]);
		return;
	}

};