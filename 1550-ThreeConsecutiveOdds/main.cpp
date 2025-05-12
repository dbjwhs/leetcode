#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool result = false;

        int odd_count = 0;
        for (auto i : arr) {
            if (i % 2 == 0) {
                odd_count = 0;
                continue;
            }
            if (++odd_count == 3) {
                result = true;
                break;
            }
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> arr{1,2,3};
        bool result = solution.threeConsecutiveOdds(arr);
        assert(result == false && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }

    {
        vector<int> arr{1,2,34,3,4,5,7,23,12};
        bool result = solution.threeConsecutiveOdds(arr);
        assert(result == true && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
