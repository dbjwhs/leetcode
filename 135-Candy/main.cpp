#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }

        const int ratingsSize = ratings.size();
        vector<int> candies(ratingsSize, 1);  // init with 1 candy per child

        // left to right pass: ensure higher rated children get more than left neighbor
        for (int ndx = 1; ndx < ratingsSize; ++ndx) {
            if (ratings[ndx] > ratings[ndx - 1]) {
                candies[ndx] = candies[ndx - 1] + 1;
            }
        }

        // right to left pass: ensure higher rated children get more than right neighbor
        for (int ndx = ratingsSize - 2; ndx >= 0; --ndx) {
            if (ratings[ndx] > ratings[ndx + 1]) {
                candies[ndx] = max(candies[ndx], candies[ndx + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

void runTests() {
    Solution solution;

    {
        vector<int> ratings = {1, 0, 2};
        int result = solution.candy(ratings);
        assert(result == 5 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        vector<int> ratings = {1, 2, 2};
        int result = solution.candy(ratings);
        assert(result == 4 && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
