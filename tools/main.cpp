#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:

};

void runTests() {
    Solution solution;

    {

        bool result = solution.
        assert(result == false && "Test 2 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }

    {

        bool result = solution.
        assert(result == false && "Test 2 failed");
        std::cout << "Test 2 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
