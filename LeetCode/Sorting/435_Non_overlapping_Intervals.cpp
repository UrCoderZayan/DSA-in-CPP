#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < end) {
                // Overlap → remove current interval
                removed++;
            }
            else {
                // No overlap → keep current interval
                end = intervals[i][1];
            }
        }

        return removed;
    }
};