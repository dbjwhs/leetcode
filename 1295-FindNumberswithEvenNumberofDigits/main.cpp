#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (auto num : nums) {
            string nextNumStr = to_string(num);
            bool numEven = true;
            for (auto ch : nextNumStr) {
                numEven == false ? numEven = true : numEven = false;
            }
            if (numEven == true) {
                result++;
            }
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> nums{12,345,2,6,7896};
        int result = solution.findNumbers(nums);
        assert(result == 2 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
