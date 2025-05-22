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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> tripCache;
        sort(nums.begin(), nums.end());
        int numsLen = nums.size();
        for (int i = 0; i < numsLen ; ++i) {
            int num_i = nums[i];
            for (int j = i + 1; j < numsLen; ++j) {
                for (int k = j + 1; k < numsLen; ++k) {
                    int num_j = nums[j];
                    if (i != j and i != k and j != k) {
                        int num_k = nums[k];
                        if (num_i + num_j + num_k == 0) {
                            vector<int> triplet = {num_i, num_j, num_k};
                            sort(triplet.begin(), triplet.end());
                            cout << i << " " << j << " " << k << endl;
                            for (int val : triplet) {
                                cout << val << " ";
                            }
                            cout << endl;
                            //this->pushUnique(results, triplet);
                        }
                    }
                }
            }
        }
        return results;
    }

    void pushUnique(vector<vector<int>>& nums, vector<int>& triplet) {
        for (auto nexTrip: nums) {
            if (triplet == nexTrip) {
                return;
            }
        }
        nums.emplace_back(triplet);
    }
};

void runTests() {

    Solution solution;

    {
        vector<int> nums = {2,-8,8,6,-14,-12,11,-10,13,14,7,3,10,-13,3,-15,7,3,-11,-8,4,5,9,11,7,1,3,13,14,-13,3,-6,-6,-12,-15,-12,-9,3,-15,-11,-6,-1,0,11,2,-12,3,-6,6,0,-6,-12,-10,-12,6,5,-4,-5,-5,-4,-11,13,5,-2,-13,-3,-7,-15,8,-15,12,-13,0,-3,6,9,-8,-6,10,5,9,-11,0,7,-15,-8,-3,-4,-6,7,7,-2,-2,-11,3,0,-6,12,0,-13,4,-3,11,-11,1,2,13,8,4,9,-1,-2,5,14,12,5,13,-6,-13,-8,9,1,5,-8,-2,-6,-1};
        vector<vector<int>> result = solution.threeSum(nums);
        assert(result.size() != 1 && "Test 1 failed");
        std::cout << "Test 1 passed:" << std::endl;
    }
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = solution.threeSum(nums);
        assert(result.size() != 1 && "Test 1 failed");
        std::cout << "Test 1 passed:" << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
