#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Given an array of integers arr, return true if there are three consecutive odd numbers in the array. 
// Otherwise, return false.

// Example 1:
// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.

// Example 2:
// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
// Explanation: [5,7,23] are three consecutive odds.

// Constraints:
// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.


// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// solution below, not mine, I got stuck on TLE on this one. e.g. my solution was too slow

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int startNdx = 0; startNdx < nums.size(); startNdx++) {
            if (startNdx > 0 && nums[startNdx] == nums[startNdx - 1]) {
                continue;
            }

            int forwardNdx = startNdx + 1;
            int backwardNdx = nums.size() - 1;
            while (forwardNdx < backwardNdx) {
                int total = nums[startNdx] + nums[forwardNdx] + nums[backwardNdx];

                if (total > 0) {
                    backwardNdx--;
                } else if (total < 0) {
                    forwardNdx++;
                } else {
                    result.push_back({nums[startNdx], nums[forwardNdx], nums[backwardNdx]});
                    forwardNdx++;

                    while (nums[forwardNdx] == nums[forwardNdx-1] && forwardNdx < backwardNdx) {
                        forwardNdx++;
                    }
                }
            }
        }
        return result;
    }
};

void runTests() {

    Solution solution;

    {
        vector<int> nums = {-14,-3,11,-3,12,-1,11,13,5,6,-11,-14,-6,11,-4,-15,3,-15,9,-10,13,-10,-9,-13,-12,12,-7,12,12,3,9,5,-14,-3,9,13,11,5,3,-6,-12,-1,-5,-3,-4,-2,-10,6,-10,14,3,-11,11,10,-9,7,-1,-9,4,-12,2,-2,8,3,3,-6,-7,-1,6,12,8,9,-12,10,-8,-1,-7,-3,12,-9,-12,1,-5,6,-12,-7,-2,2,-8,-13,5,9,-7,-10,-3,11,-1,-3,-13,-10,-14,11,6,-10,6,13,4,7,-13,-6,13,12,10,-15,4,13,-7,9,-8,0,4,4,-6,12,9,-2,0};
        vector<vector<int>> result = solution.threeSum(nums);
        assert(result.size() == 118 && "Test 1 failed");
        std::cout << "Test 1 passed:" << std::endl;
    }
    {
        vector<int> nums = {2,-8,8,6,-14,-12,11,-10,13,14,7,3,10,-13,3,-15,7,3,-11,-8,4,5,9,11,7,1,3,13,14,-13,3,-6,-6,-12,-15,-12,-9,3,-15,-11,-6,-1,0,11,2,-12,3,-6,6,0,-6,-12,-10,-12,6,5,-4,-5,-5,-4,-11,13,5,-2,-13,-3,-7,-15,8,-15,12,-13,0,-3,6,9,-8,-6,10,5,9,-11,0,7,-15,-8,-3,-4,-6,7,7,-2,-2,-11,3,0,-6,12,0,-13,4,-3,11,-11,1,2,13,8,4,9,-1,-2,5,14,12,5,13,-6,-13,-8,9,1,5,-8,-2,-6,-1};
        vector<vector<int>> result = solution.threeSum(nums);
        assert(result.size() == 119 && "Test 1 failed");
        std::cout << "Test 1 passed:" << std::endl;
    }
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = solution.threeSum(nums);
        assert(result.size() == 2 && "Test 1 failed");
        std::cout << "Test 1 passed:" << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
