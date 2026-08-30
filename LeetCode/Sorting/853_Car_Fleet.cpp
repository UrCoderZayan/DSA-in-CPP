#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++) {

            double time =
                (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(),
             [](const pair<int, double>& a,
                const pair<int, double>& b) {
                 return a.first > b.first;
             });

        int fleets = 0;
        double slowestTime = 0;

        for (auto& car : cars) {

            if (car.second > slowestTime) {
                fleets++;
                slowestTime = car.second;
            }
        }

        return fleets;
    }
};