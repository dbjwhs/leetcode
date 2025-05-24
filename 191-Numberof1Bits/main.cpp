#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int bits = 0;
        while (n != 0) {
            n &= n - 1;
            bits++;
        }
        return bits;
    }
};
void runTests() {
    Solution solution;

    {

        int result = solution.hammingWeight(11);
        assert(result == 3 && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
