#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == INT_MIN or n == 0) {
            return false;
        }
        n = n &= (n - 1);
        return n == 0;
    }
};

void runTests() {
    Solution solution;

    {
        int n = -2147483648;
        bool result = solution.isPowerOfTwo(n);
        assert(result == false && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
    {
        int n = 16;
        bool result = solution.isPowerOfTwo(n);
        assert(result == true && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
    {
        int n = 3;
        bool result = solution.isPowerOfTwo(n);
        assert(result == false && "Test 3 failed");
        std::cout << "Test 3 passed: " << result << std::endl;
    }
    {
        int n = 6;
        bool result = solution.isPowerOfTwo(n);
        assert(result == false && "Test 4 failed");
        std::cout << "Test 4 passed: " << result << std::endl;
    }
    {
        int n = 0;
        bool result = solution.isPowerOfTwo(n);
        assert(result == false && "Test 5 failed");
        std::cout << "Test 5 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
