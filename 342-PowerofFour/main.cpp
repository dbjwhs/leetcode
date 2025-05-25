#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        bool result = false;
        int ndx = 0;
        while (true) {
            long long nextPower = pow(4, ndx);
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
        int n = 16;
        bool result = solution.isPowerOfFour(n);
        assert(result == true && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
