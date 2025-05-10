#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>

class Solution {
public:
    int countBalancedPermutations(std::string num) {
        constexpr int kMod = 1000000007;
        std::vector<int> digits;

        // if the total sum is odd, no balanced permutation is possible since all the numbers will add
        // up to the same value; we can optimize this by returning 0
        for (char num_char : num) {
            digits.push_back(num_char - '0');
        }
        int sum = std::accumulate(digits.begin(), digits.end(), 0);
        if (sum % 2 != 0) {
            return 0;
        }

        // do work
        int total_balanced = 0;
        int num_len = num.length();
        std::sort(digits.begin(), digits.end());
        do {
            int evenSum = 0;
            int oddSum = 0;
            for (int ndx = 0; ndx < num_len; ++ndx) {
                if (ndx % 2 == 0) {
                    evenSum += digits[ndx];
                } else {
                    oddSum += digits[ndx];
                }
            }
            if (evenSum == oddSum) {
                total_balanced = (total_balanced + 1) % kMod;
            }
        } while (std::next_permutation(digits.begin(), digits.end()));

        return total_balanced;
    }
};

// Test function with detailed output
void runTest(const std::string& num, int expected) {
    Solution solution;
    int result = solution.countBalancedPermutations(num);

    std::cout << "Input: \"" << num << "\"" << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Result: " << result << std::endl;


    if (result == expected) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
        assert(result == expected);
    }
    std::cout << "----------------------------" << std::endl;
}

int main() {
    // fails: 0(n!) :-( .. runTest("0593136364172", 2);
    runTest("123", 2);
    runTest("112", 1);
    runTest("12345", 0);
    runTest("1100", 4);
    runTest("1234", 8);
    std::cout << "Done" << std::endl;
    return 0;
}
