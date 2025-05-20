#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> uNums{nums.begin(), nums.end()};
        int ndx = 0;
        for (int num : uNums) {
            nums[ndx] = num;
            ndx++;
        }
        return ndx;
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> nums = {1, 1, 2};
        int result = solution.removeDuplicates(nums);
        assert(result == 2 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
