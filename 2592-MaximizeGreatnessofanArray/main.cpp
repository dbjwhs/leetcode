#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/*
Leetcode problem 2592. Maximize Greatness of an Array
https://leetcode.com/problems/maximize-greatness-of-an-array/description/
Difficulty: Medium

You are given a 0-indexed integer array nums. You are allowed to permute nums
into a new array perm of your choosing.

We define the greatness of nums be the number of indices 0 <= i < nums.length
for which perm[i] > nums[i].

Return the maximum possible greatness you can achieve after permuting nums.



Example 1:

Input: nums = [1,3,5,2,1,3,1]
Output: 4
Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.

Example 2:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.




Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109

*/

using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> reNums = nums;
        int result = 0;
        for (int ndx = 0; ndx < nums.size() && reNums.size() != 0; ++ndx) {
            for (int rdx = 0; rdx < reNums.size(); ++rdx) {
                if (reNums[rdx] > nums[ndx]) {
                    ++result;
                    reNums.erase(reNums.begin(), reNums.begin() + rdx + 1);
                    break;
                }
            }
        }
        return result;
    }
};


void runTests() {
    Solution solution;

    {
        vector<int> nums = {1, 3, 5, 2, 1, 3, 1};
        int result = solution.maximizeGreatness(nums);
        assert(result == 4 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        vector<int> nums = {1, 2, 3, 4};
        int result = solution.maximizeGreatness(nums);
        assert(result == 3 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
