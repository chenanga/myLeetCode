#include "general.h"

class Solution {

private:
    struct myCmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num] ++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> small_heap;

        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            if (small_heap.size() < k) {
                small_heap.push({ (*iter).first, (*iter).second });
            }
            else {
                if (small_heap.top().second < (*iter).second) {
                    small_heap.pop();
                    small_heap.push({ (*iter).first, (*iter).second });
                }
            }
        }
        vector<int> res;
        while (!small_heap.empty()) {
            res.push_back(small_heap.top().first);
            small_heap.pop();
        }
        return res;

    }
};