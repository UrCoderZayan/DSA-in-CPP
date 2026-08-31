#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numbers(nums1.begin(), nums1.end());
        unordered_set<int> intersectionSet;

        for (int num : nums2) {
            if (numbers.find(num) != numbers.end()) {
                intersectionSet.insert(num);
            }
        }

        return vector<int>(intersectionSet.begin(), intersectionSet.end());
    }
};