#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        // 0 cannot be represented as sum of positive powers
        if (n <= 0) {
            return false;
        }

        // convert to base 3 and check each digit
        while (n > 0) {
            // if any digit in base-3 representation is ≥ 2,
            // we'd need to use the same power of 3 multiple times
            if (const int remainder = n % 3; remainder >= 2) {
                return false;
            }
            // move to the next digit (higher power of 3)
            n /= 3;
        }
        return true;
    }
};

void runTests() {
    Solution solution;

    {
        int n = 91;
        bool result = solution.checkPowersOfThree(n);
        assert(result == true && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        int n = 21;
        bool result = solution.checkPowersOfThree(n);
        assert(result == false && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        int n = 12;
        bool result = solution.checkPowersOfThree(n);
        assert(result == true && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
