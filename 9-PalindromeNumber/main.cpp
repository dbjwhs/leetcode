#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string input = to_string(x);
        string reversed = input;
        reverse(input.begin(), input.end());
        return input == reversed;
    }
};

void runTests() {
    Solution solution;

    {
        int num = 121;
        bool result = solution.isPalindrome(num);
        assert(result == true && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
