#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// I asked Claude 4.0 to come up with a fast solution, here it is. Are we doomed?

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Swap consecutive pairs
        n = ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA) >> 1);

        // Swap consecutive pairs of pairs
        n = ((n & 0x33333333) << 2) | ((n & 0xCCCCCCCC) >> 2);

        // Swap consecutive quads
        n = ((n & 0x0F0F0F0F) << 4) | ((n & 0xF0F0F0F0) >> 4);

        // Swap consecutive bytes
        n = ((n & 0x00FF00FF) << 8) | ((n & 0xFF00FF00) >> 8);

        // Swap consecutive pairs of bytes
        n = (n << 16) | (n >> 16);

        return n;
    }
};

void runTests() {
    Solution solution;

    {
        uint32_t n = solution.createFromBitset("00000010100101000001111010011100");
        uint32_t result = solution.reverseBits(n);
        string resultStr = solution.bitsetToString(result);
        string expectedResultStr = solution.bitsetToString(964176192);
        assert(resultStr == expectedResultStr && "Test 1 failed");
        std::cout << "Test 1 passed: " << result << std::endl;
    }
}

int main() {
    runTests();
    std::cout << "All Tests Passed" << std::endl;
    return 0;
}
