#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> elements;

        for (auto& [num, count] : freq) {
            elements.push_back({num, count});
        }

        sort(elements.begin(), elements.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {
                 return a.second > b.second;
             });

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(elements[i].first);
        }

        return result;
    }
};
