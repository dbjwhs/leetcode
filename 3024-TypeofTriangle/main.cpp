#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (triangleValid(nums) == false) {
            return "none";
        }
        if (triangleEquilateral(nums)) {
            return "equilateral";
        }
        if (triangleIsosceles(nums)) {
            return "isosceles";
        }
        return "scalene";
    }

private:
    bool triangleValid(const vector<int>& nums) {
        return (nums[0] + nums[1] > nums[2]
            and nums[0] + nums[2] > nums[1]
            and nums[1] + nums[2] > nums[0]);
    }

    bool triangleEquilateral(const vector<int>& nums) {
        return nums[0] == nums[1]and nums[1] == nums[2];
    }

    bool triangleIsosceles(const vector<int>& nums) {
        return nums[0] == nums[1] or nums[1] == nums[2] or nums[0] == nums[2];
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> nums = {3, 3, 3};
        string result = solution.triangleType(nums);
        assert(result == "equilateral" && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {
        vector<int> nums = {3, 4, 5};
        string result = solution.triangleType(nums);
        assert(result == "scalene" && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
