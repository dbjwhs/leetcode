/*
Leetcode problem 2442. Count Number of Distinct Integers After Reverse Operations
https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
Difficulty: Medium

You are given an array nums consisting of positive integers.

You have to take each integer in the array, reverse its digits, and add it to
the end of the array. You should apply this operation to the original integers
in nums.

Return the number of distinct integers in the final array.



Example 1:

Input: nums = [1,13,10,12,31]
Output: 6
Explanation: After including the reverse of each number, the resulting array is
[1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined.
Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13,
21, and 31).

Example 2:

Input: nums = [2,2,2]
Output: 1
Explanation: After including the reverse of each number, the resulting array is
[2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        // first add our nums and the reverse of our nums to set
        for (const int num : nums) {

            // version 1
            //string numStr = to_string(num);
            //reverse(numStr.begin(), numStr.end());
            //uniqueNums.insert(atoi(numStr.c_str()));

            // version 2 (much faster, of course)
            uniqueNums.insert(this->reverseInt(num));
        }
        return uniqueNums.size();
    }

    int reverseInt(int num) {
        int revNum = 0;
        while (num > 0) {
            revNum *= 10;
            revNum += (num % 10);
            num /= 10;
        }
        return revNum;
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> nums = {1, 13, 10, 12, 31};
        int result = solution.countDistinctIntegers(nums);
        assert(result == 6 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
