#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        bool result = false;
        int ndx = 0;
        while (true) {
            long long nextPower = pow(3, ndx);
            if (nextPower == n) {
                result = true;
                break;
            }
            if (nextPower > n) {
                break;
            }
            ++ndx;
        }
        return result;
    }
};

void runTests() {
    Solution solution;

    {
        int n = 27;
        bool result = solution.isPowerOfThree(n);
        assert(result == true && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        int n = 9;
        bool result = solution.isPowerOfThree(n);
        assert(result == true && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        int n = 0;
        bool result = solution.isPowerOfThree(n);
        assert(result == false && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        int n = 1162261467;
        bool result = solution.isPowerOfThree(n);
        assert(result == true && "Test 4 failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
    {
        int n = 1162261468;
        bool result = solution.isPowerOfThree(n);
        assert(result == false && "Test 5 failed");
        std::cout << "Test 5 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
