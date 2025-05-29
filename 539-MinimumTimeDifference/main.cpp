#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// 539. Minimum Time Difference
// Medium
// Topics
// premium lock icon
// Companies
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
//
//
// Example 1:
//
// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:
//
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
//
//
// Constraints:
//
// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> pureMinutes;
        for (const auto& nextTime : timePoints) {
            pureMinutes.push_back(abs((stoi(nextTime.substr(0, 2)) * 60 + stoi(nextTime.substr(3, 2)))));
        }

        ranges::sort(pureMinutes);

        int minDiff = INT_MAX;
        for (int ndx = 0; ndx < pureMinutes.size() - 1; ++ndx) {
            if (const int nextDiff = pureMinutes[ndx + 1] - pureMinutes[ndx]; nextDiff < minDiff) {
                minDiff = nextDiff;
            }
        }

        if (const int overFlowDiff = pureMinutes[0] + (1440 - pureMinutes[pureMinutes.size() - 1]); overFlowDiff < minDiff) {
            minDiff = overFlowDiff;
        }

        return minDiff;
    }
};

void runTests() {
    Solution solution;

    {
        vector<string> timepoints = {"23:59", "00:00"};
        int result = solution.findMinDifference(timepoints);
        assert(result == 1 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        vector<string> timepoints = {"01:01","02:01","03:00"};
        int result = solution.findMinDifference(timepoints);
        assert(result == 59 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        vector<string> timepoints = {"02:39","10:26","21:43"};
        int result = solution.findMinDifference(timepoints);
        assert(result == 296 && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        vector<string> timepoints = {"12:01","00:10","00:01"};
        int result = solution.findMinDifference(timepoints);
        assert(result == 9 && "Test 4x failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
