/*
Leetcode problem 89. Gray Code
https://leetcode.com/problems/gray-code/description/
Difficulty: Medium

An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly
one bit, and
The binary representation of the first and last integers differs by exactly one
bit.

Given an integer n, return any valid n-bit gray code sequence.



Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is
[00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit


Example 2:

Input: n = 1
Output: [0,1]




Constraints:

1 <= n <= 16

*/


#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    static vector<int> grayCode(int n) {
        // account for 0 and 1
        if (n == 0) {
            return {0};
        }
        if (n == 1) {
            return {0, 1};
        }

        // get the (n-1)-bit Gray code sequence
        vector<int> prev = grayCode(n - 1);
        vector<int> result = prev;

        // add the reversed sequence with the nth bit set
        int highBit = 1 << (n - 1);  // 2^(n-1)

        // iterate through a previous sequence in reverse order
        for (int ndx = static_cast<int>(prev.size()) - 1; ndx >= 0; --ndx) {
            result.push_back(prev[ndx] | highBit);
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        int n = 2;
        vector<int> expected = {0, 1, 3, 2};
        vector<int> result = solution.grayCode(n);
        assert(result == expected && "Test 1 failed");
        cout << "Test 1 passed:" << endl;
    }
}

int main() {
    runTests();
    cout << "All Tests Passed" << endl;
    return 0;
}
