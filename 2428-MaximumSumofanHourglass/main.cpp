#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/*
Leetcode problem 2428. Maximum Sum of an Hourglass
https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/
Difficulty: Medium

You are given an m x n integer matrix grid.

We define an hourglass as a part of the matrix with the following form:

Return the maximum sum of the elements of an hourglass.

Note that an hourglass cannot be rotated and must be entirely contained within
the matrix.



Example 1:

Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
Output: 30
Explanation: The cells shown above represent the hourglass with the maximum sum:
6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.


Example 2:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 35
Explanation: There is only one hourglass in the matrix, with the sum: 1 + 2 + 3
+ 5 + 7 + 8 + 9 = 35.




Constraints:

m == grid.length
n == grid[i].length
3 <= m, n <= 150
0 <= grid[i][j] <= 106

*/


class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxResult = 0;
        for (int ndx = 0; ndx < grid.size() - 2; ++ndx) {
            for (int vdx = 0; vdx < grid[ndx].size() - 2; ++vdx) {
                int nextResult = grid[ndx][vdx] + grid[ndx][vdx + 1] + grid[ndx][vdx + 2]
                + grid[ndx + 1][vdx + 1]
                + grid[ndx + 2][vdx] + grid[ndx + 2][vdx + 1] + grid[ndx + 2][vdx + 2];
                if (nextResult > maxResult) {
                    maxResult = nextResult;
                }
            }
            cout << endl;
        }
        return maxResult;
    }
};


void runTests() {
    Solution solution;

    {
        vector<vector<int>> grid = {{6,2,1,3}, {4,2,1,5}, {9,2,8,7}, {4,1,2,9}};
        int result = solution.maxSum(grid);
        assert(result == 30 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
